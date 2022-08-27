/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:33 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 17:16:59 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/vector.h"
#include "../libft/libft.h"

// Name as in bash variable name characters
bool	is_name(char c)
{
	return (ft_isalpha(c) || c == '_');
}

/*
 * Tokenizes a word until it's not a name
 * */
// TODO: Not done yet!
t_token	*tokenize_var(char **str, t_state *state)
{
	t_token	*token;
	t_cvec	*vec;

	(void)state;
	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	vec = cvec_new(32);
	if (vec == NULL)
		return (NULL);
	if (**str != '$')
		return (NULL);
	cvec_append(vec, '$');
	(*str)++;
	while (is_name(**str))
	{
		cvec_append(vec, **str);
		(*str)++;
	}
	token->str = vec->arr;
	token->len = vec->len;
	free(vec);
	return (token);
}
