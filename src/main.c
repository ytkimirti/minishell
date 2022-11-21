/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 14:42:00 by ykimirti         ###   ########.tr       */
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

#include <stdio.h>
#include <sys/wait.h>
#include "utils.h"
#include "ast_utils.h"

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
		end_trace();
		execute_and_set_status(tree);
		while (waitpid(-1, 0, 0) != -1)
			;
		free_tokens(tokens);
		free_tree(tree);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	init_env(envp);
	shell_loop();
}
