/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/06 11:48:22 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/vector.h"
#include "tokenizer.h"
#include "token.h"
#include "executer.h"
#include "parser.h"

int	main(void)
{
	char	*line;
	t_token	**t;
	t_cmd	cmd;

	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		t = tokenize(line);
		cmd = create_cmd(t);
		execute_cmd(&cmd);
		free_tokens(t);
		free_cmd(&cmd);
	}
}
