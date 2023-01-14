/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:44:54 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/14 12:07:30 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_utils.h"
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
#include "utils.h"
#include <sys/wait.h>
#include "env.h"

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
		exit(run_expr(tokens, std));
	}
	status = 0;
	if (is_sync)
	{
		waitpid(pid, &status, 0);
		status = WEXITSTATUS(status);
	}
	*tokens = jump_paren(*tokens) + 1;
	skip_spaces(tokens);
	return (status);
}

// This is the end, this is where everything gets set. So we can
// just set the last status here!
int	run_primary(t_token ***tokens, t_stdio std, bool is_sync)
{
	int			status;
	char		*str;

	skip_spaces(tokens);
	if (**tokens == NULL)
		return (error_unexpected(**tokens, EMPTY), SHELL_ERROR);
	if ((**tokens)->type == PAREN_OPEN)
		status = (run_paren(tokens, std, is_sync));
	else if (is_command_token(**tokens))
		status = parse_and_run_command(tokens, std, is_sync);
	else
		status = (error_unexpected(**tokens, EMPTY), SHELL_ERROR);
	str = ft_itoa(status);
	set_env("?", str);
	free(str);
	return (status);
}

// TODO: Protect the pipe syscall against error
// But no more lines, so pfff
int	run_pipeline(t_token ***tokens, t_stdio std, bool is_sync)
{
	int	fds[2];
	int	original_out;
	int	status;

	original_out = std.out;
	while (is_next_pipeline(*tokens))
	{
		pipe(fds);
		std.out = fds[1];
		ivec_append(std.unwanted_fds, fds[0]);
		if (run_primary(tokens, std, false) == SHELL_ERROR)
			return (SHELL_ERROR);
		close(fds[1]);
		std.unwanted_fds->len--;
		close_if_not_eq(std.in, 0);
		std.in = fds[0];
		(*tokens)++;
	}
	std.out = original_out;
	status = run_primary(tokens, std, true);
	close_if_not_eq(std.in, 0);
	while (is_sync && waitpid(-1, 0, 0) != -1)
		;
	return (status);
}

int	run_expr(t_token ***tokens, t_stdio std)
{
	int	last_status;

	last_status = run_pipeline(tokens, std, true);
	if (last_status == SHELL_ERROR)
		return (SHELL_ERROR);
	while (**tokens != NULL
		&& ((**tokens)->type == OR_TOKEN
			|| (**tokens)->type == AND_TOKEN))
	{
		if ((**tokens)->type == OR_TOKEN && last_status == 0)
		{
			*tokens = jump_to_end(*tokens);
			return (0);
		}
		else if ((**tokens)->type == AND_TOKEN && last_status != 0)
		{
			*tokens = jump_to_end(*tokens);
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
	status = run_expr(&tokens, (t_stdio){0, 1, 2, unwanted});
	if (*tokens != NULL)
	{
		error_unexpected(*tokens, EMPTY);
		return (ivec_del(unwanted), SHELL_ERROR);
	}
	ivec_del(unwanted);
	return (status);
}
