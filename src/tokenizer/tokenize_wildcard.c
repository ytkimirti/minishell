/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_wildcard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/09 21:26:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "tokenize_state.h"
#include "token.h"
#include "libft.h"
#include "error.h"

bool	is_wildcard_token(const t_token *token)
{
	if (token == NULL)
		return (false);
	return (token->type == WILDCARD_TOKEN
		|| token->type == QUESTION_TOKEN);
}

t_token	*tokenize_wildcard(char **str, t_state *state)
{
	t_token	*token;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	if (**str == '*')
		token->type = WILDCARD_TOKEN;
	else if (**str == '?')
		token->type = QUESTION_TOKEN;
	(*str)++;
	return (token);
}
