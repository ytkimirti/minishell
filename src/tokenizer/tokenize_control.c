/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 15:51:52 by ykimirti         ###   ########.tr       */
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

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (**str == '&')
		token->type = AND_TOKEN;
	else if (**str == '|')
		token->type = OR_TOKEN;
	(*str) += 2;
	return (token);
}
