/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 14:12:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_token	**t;
	t_node	*tree;

	(void)argc;
	(void)argv;
	(void)envp;
	init_env(envp);
	while (true)
	{
		line = readline_with_prompt();
		if (line == NULL)
			break ;
		line[ft_strlen(line)] = '\0';
		t = tokenize(line);
		begin_trace(t, line);
		tree = build_tree(t);
		print_tree(tree);
		end_trace();
		execute_tree(tree);
		while (waitpid(-1, 0, 0) != -1)
			;
		free_tokens(t);
		free_tree(tree);
	}
}
