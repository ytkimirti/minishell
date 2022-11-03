/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:10:57 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prompt/prompt.h"
#include "prompt/prompt_utils.h"
#include "vector.h"
#include "tokenizer.h"
#include "token.h"
#include "parser.h"

#include <stdio.h>
#include "utils.h"

int	main(void)
{
	char	*line;
	t_token	**t;

	while (true)
	{
		line = readline_with_prompt();
		if (line == NULL)
			break ;
		line[ft_strlen(line)] = '\0';
		t = tokenize(line);
		free_tokens(t);
	}
}
