/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_paren.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:10:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "libft.h"
#include "error.h"

t_token	*tokenize_paren(char **str, t_state *state)
{
	t_token	*token;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	if (**str == '(')
		token->type = PAREN_OPEN;
	else if (**str == ')')
		token->type = PAREN_CLOSE;
	(*str)++;
	return (token);
}
