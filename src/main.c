/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 21:13:30 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "env.h"
#include "error.h"
#include "libft.h"
#include "prompt/prompt.h"
#include "prompt/prompt_utils.h"
#include "vector.h"
#include "tokenizer.h"
#include "token.h"
#include "parser.h"

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include "utils.h"
#include "ast_utils.h"
#include "readline/readline.h"

static void	execute_and_set_status(t_node *tree)
{
	int			status;
	static int	last_status = -1;
	char		*tmp_str;

	status = execute_tree(tree);
	if (status == last_status)
		return ;
	last_status = status;
	tmp_str = ft_itoa(status);
	set_env("?", tmp_str);
	free(tmp_str);
}

static void	shell_loop(void)
{
	char	*line;
	t_token	**tokens;
	t_node	*tree;

	while (true)
	{
		line = readline_with_prompt();
		if (line == NULL)
			break ;
		line[ft_strlen(line)] = '\0';
		tokens = tokenize(line);
		begin_trace(tokens, line);
		tree = build_tree(tokens);
		print_tree(tree);
		// print_tokens(t);
		end_trace();
		execute_and_set_status(tree);
		while (waitpid(-1, 0, 0) != -1)
			;
		free_tokens(tokens);
		free_tree(tree);
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (waitpid(-1, 0, 0) != -1)
			return ;
		rl_replace_line("", 1);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	init_env(envp);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	shell_loop();
}
