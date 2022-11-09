/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/09 17:46:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "coz.h"
#include "env.h"
#include "libft.h"
#include "prompt/prompt.h"
#include "prompt/prompt_utils.h"
#include "vector.h"
#include "tokenizer.h"
#include "token.h"
#include "parser.h"

#include <stdio.h>
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
		tree = build_tree(t);
		free_tokens(t);
		free_tree(tree);
		COZ_PROGRESS;
	}
}
