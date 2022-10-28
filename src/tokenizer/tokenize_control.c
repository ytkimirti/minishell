/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:32:25 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/libft.h"

/*
 * Tokenizes control characters () && || |
 * */
t_token	*tokenize_control(char **str, t_state *state)
{
	t_token	*token;

	if (state->in_quotes)
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = SPACE;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (token);
}
