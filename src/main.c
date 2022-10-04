/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:18:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/04 16:34:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/vector.h"
#include "tokenizer.h"
#include "token.h"
#include "executer.h"

// This is only for debugging.
t_cmd	execute_cmd_with_tokens(t_token **tokens)
{
	t_cmd 	cmd;
	int		i;

	cmd.stdin = 0;
	cmd.stdout = 1;
	cmd.stderr = 0;

	while (&tokens[i] != NULL)
	{
		i++;
	}
	return (cmd);
}

int	main(void)
{
	char	*line;
	t_token **t;

	while (true)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		// ft_printf("%s\n", line);
		t = tokenize(line);
		execute_cmd_with_tokens(t);
		free(t);
	}
}
