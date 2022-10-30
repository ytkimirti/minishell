/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 18:03:59 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include <stdlib.h>

t_token	*tokenize_quote(const char **str, t_state *state)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (**str == '\"')
	{
		state->in_quotes = !state->in_quotes;
		token->type = DOUBLE_QUOTE;
	}
	else if (**str == '\'')
	{
		state->in_squotes = !state->in_squotes;
		token->type = SINGLE_QUOTE;
	}
	return (token);
}
