/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:38:23 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/libft.h"

t_token	*tokenize_quote(char **str, t_state *state)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (**str == '\"')
	{
		if (state->in_quotes)
			token->type = QUOTE_CLOSE;
		else
			token->type = QUOTE_OPEN;
	}
	else if (**str == '\'')
	{
		if (state->in_quotes)
			token->type = SQUOTE_CLOSE;
		else
			token->type = SQUOTE_CLOSE;
	}
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (token);
}
