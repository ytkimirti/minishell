/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:44:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/27 16:33:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token.h"
#include "parser_utils.h"
#include <stdlib.h>
#include <assert.h>
#include "parser.h"
#include "ast.h"
#include "ast_utils.h"
#include "tstdio.h"
#include <stdio.h>
#include <unistd.h>
#include "error.h"
#include "libft.h"

int	parse_and_run_command(t_token ***tokens, t_stdio std, bool is_sync)
{
	t_command	*command;
	int			status;

	command = create_command(tokens);
	if (command == NULL)
		return (SHELL_ERROR);
	status = execute_command(command, std, is_sync);
	free(command);
	return (status);
}

int	run_expr(t_token ***tokens, t_stdio std, bool is_sync);

t_token	**jump_paren(t_token **tokens)
{
	int	depth;

	assert(*tokens != NULL && (*tokens)->type == PAREN_OPEN);
	depth = 0;
	while (*tokens != NULL)
	{
		if ((*tokens)->type == PAREN_OPEN)
			depth++;
		if ((*tokens)->type == PAREN_CLOSE)
			depth--;
		if (depth == 0)
			return (tokens);
		tokens++;
	}
	return (tokens);
}

t_token	**jump_primary(t_token **tokens)
{
	if ((*tokens)->type == PAREN_OPEN)
		return (jump_paren(tokens));
	while (*tokens != NULL && (is_command_token(*tokens)
			|| (*tokens)->type == SPACE_TOKEN))
		tokens++;
	return (tokens);
}

t_token	**jump_pipeline(t_token **tokens)
{
	tokens = jump_primary(tokens);
	while ((*tokens) != NULL && (*tokens)->type == PIPE_TOKEN)
	{
		tokens++;
		tokens = jump_pipeline(tokens);
	}
	return (tokens);
}

bool	is_next_pipeline(t_token **tokens)
{
	t_token	**jumped;

	jumped = jump_primary(tokens);
	skip_spaces(&jumped);
	if (*jumped == NULL)
		return (false);
	return ((*jumped)->type == PIPE_TOKEN);
}

int	run_paren(t_token ***tokens, t_stdio std, bool is_sync)
{
	int	pid;
	int	status;

	if (*jump_paren(*tokens) == NULL)
		return (error_unexpected(NULL, PAREN_CLOSE), SHELL_ERROR);
	pid = fork();
	if (pid == -1)
		return (perror("fork error"), SHELL_ERROR);
	if (pid == 0)
	{
		(*tokens)++;
		exit(run_expr(tokens, std, is_sync));
	}
	status = 0;
	if (is_sync)
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
	}
	*tokens = jump_paren(*tokens) + 1;
	return (status);
}

int	run_primary(t_token ***tokens, t_stdio std, bool is_sync)
{
	skip_spaces(tokens);
	if (**tokens == NULL)
		return (error_unexpected(**tokens, EMPTY), SHELL_ERROR);
	if ((**tokens)->type == PAREN_OPEN)
		return (run_paren(tokens, std, is_sync));
	else if (is_command_token(**tokens))
		return (parse_and_run_command(tokens, std, is_sync));
	else
		return (error_unexpected(**tokens, EMPTY), SHELL_ERROR);
}

static void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror("ft_close error");
}

int	run_pipeline(t_token ***tokens, t_stdio std, bool is_sync)
{
	int	fds[2];
	int	original_out;
	int	status;

	original_out = std.out;
	while (is_next_pipeline(*tokens))
	{
		if (pipe(fds) == -1)
			return (perror("pipe error"), SHELL_ERROR);
		std.out = fds[1];
		ivec_append(std.unwanted_fds, fds[0]);
		if (run_primary(tokens, std, false) == SHELL_ERROR)
			return (SHELL_ERROR);
		if (**tokens == NULL || (**tokens)->type != PIPE_TOKEN)
			break ;
		close(fds[1]);
		std.unwanted_fds->len--;
		std.in = fds[0];
		(*tokens)++;
	}
	ivec_append(std.unwanted_fds, std.in);
	std.out = original_out;
	status = run_primary(tokens, std, true);
	while (is_sync && waitpid(-1, 0, 0) != -1)
		;
	return (status);
}

// int	run_pipeline(t_token ***tokens, t_stdio std, bool is_sync)
// {
// 	int	fds[2];
// 	int	tmp;
// 	int	status;
//
// 	tmp = 0;
// 	while (is_next_pipeline(*tokens))
// 	{
// 		if (pipe(fds) == -1)
// 			return (perror("pipe error"), SHELL_ERROR);
// 		dprintf(2, "pipe %d %d\n", fds[1], fds[0]);
// 		std.in = tmp;
// 		std.out = fds[1];
// 		if (run_primary(tokens, std, false) == SHELL_ERROR)
// 			return (SHELL_ERROR);
// 		if (tmp != 0)
// 		{
// 			close(tmp);
// 			dprintf(2, "close orta temp(%d)\n", tmp);
// 		}
// 		close(fds[1]);
// 		dprintf(2, "close fds[1](%d)\n", fds[1]);
// 		tmp = fds[0];
// 		(*tokens)++;
// 	}
// 	std.out = 1;
// 	std.in = tmp;
// 	status = run_primary(tokens, std, true);
// 	if (tmp != 0)
// 	{
// 		close(tmp);
// 		dprintf(2, "close tmp(%d)\n", tmp);
// 	}
// 	while (is_sync && waitpid(-1, 0, 0) != -1)
// 		;
// 	return (status);
// }
//
int	run_expr(t_token ***tokens, t_stdio std, bool is_sync)
{
	int	last_status;

	(void)is_sync;
	last_status = run_pipeline(tokens, std, true);
	if (last_status == SHELL_ERROR)
		return (SHELL_ERROR);
	while (**tokens != NULL
		&& ((**tokens)->type == OR_TOKEN
			|| (**tokens)->type == AND_TOKEN))
	{
		if ((**tokens)->type == OR_TOKEN && last_status == 0)
		{
			*tokens = jump_pipeline(++(*tokens));
			return (0);
		}
		else if (last_status != 0)
		{
			*tokens = jump_pipeline(++(*tokens));
			return (last_status);
		}
		(*tokens)++;
		last_status = run_pipeline(tokens, std, true);
		if (last_status == SHELL_ERROR)
			return (SHELL_ERROR);
	}
	return (last_status);
}

// exit 23 && echo 
//
// echo | cat | cat
// echo | cat | ( asldk adks lajdlskd j)

// AST Syntax
// expr -> pipeline ( ( "&&" | "||" ) pipeline )*
// pipeline -> primary ( "|" primary )*
// primary -> command | ( "(" expr ")" )
int	execute_tokens(t_token **tokens)
{
	int		status;
	t_ivec	*unwanted;

	unwanted = ivec_new(10);
	status = run_expr(&tokens, (t_stdio){0, 1, 2, unwanted}, true);
	if (*tokens != NULL)
	{
		error_unexpected(*tokens, EMPTY);
		return (SHELL_ERROR);
	}
	return (status);
}
