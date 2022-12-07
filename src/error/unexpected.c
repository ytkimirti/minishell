/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:54:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/26 22:14:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "error_utils.h"
#include "printf.h"
#include "token.h"
#include <stdbool.h>
#include "print.h"
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "utils.h"

static void	print_char(char c, int count)
{
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}
}

static void	highlight_token(const t_token *token)
{
	t_errdata	*data;
	int			i;
	int			len;
	int			pos;

	data = get_errdata_singleton();
	print_colored_tokens(data->line, data->tokens);
	i = 0;
	pos = 0;
	while (data->tokens[i] != NULL && data->tokens[i] != token)
	{
		len = find_token_len(data->tokens[i]);
		if (data->tokens[i]->type == SPACE_TOKEN)
			write(1, data->line + pos, len);
		else
			print_char(' ', len);
		i++;
		pos += len;
	}
	ft_putstr(BRED);
	if (token == NULL)
		write(1, "^", 1);
	else
		print_char('^', find_token_len((t_token *)token));
	ft_putstr(RST "\n");
}

void	error_unexpected(const t_token *token, t_token_type expected)
{
	t_errdata	*data;

	data = get_errdata_singleton();
	if (data->is_tracing)
		return ;
	data->is_tracing = true;
	highlight_token(token);
	if (expected == EMPTY)
	{
		if (token == NULL)
			ft_printf(RED "Expected token" RST "\n");
		else
			ft_printf(RED "Unexpected token" RST "\n");
	}
	else
		ft_printf(RED "Expected " YEL "%s" RST "\n",
			token_type_repr(expected));
}
