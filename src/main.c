/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/14 17:15:35 by ykimirti         ###   ########.tr       */
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
#include "new.h"

static void	shell_loop(void)
{
	char	*line;
	t_token	**tokens;

	while (true)
	{
		line = readline_with_prompt();
		if (line == NULL)
			break ;
		tokens = tokenize(line);
		if (tokens == NULL || tokens[0] == NULL
			|| (tokens[0]->type == SPACE_TOKEN && tokens[1] == NULL))
		{
			(free(line), free_tokens(tokens));
			continue ;
		}
		begin_trace(tokens, line);
		execute_tokens(tokens);
		end_trace();
		while (waitpid(-1, 0, 0) != -1)
			;
		free_tokens(tokens);
		free(line);
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
		set_env("?", "1");
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
	set_env("?", "0");
	shell_loop();
}
