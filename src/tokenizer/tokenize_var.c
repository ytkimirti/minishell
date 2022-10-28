/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:33 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 17:27:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/vector.h"
#include "../libft/libft.h"

// Name as in bash variable name characters
static bool	is_name(char c)
{
	return (ft_isalpha(c) || c == '_');
}

/*
 * Tokenizes a word until it's not a name. Skips the
 * first '$' character. Pointer points after that.
 * */
t_token	*tokenize_var(char **str, t_state *state)
{
	t_token	*token;
	int		i;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	(*str)++;
	i = 0;
	while (is_name((*str)[i]))
		i++;
	token->type = VAR;
	token->str = *str;
	token->len = i;
	(*str) += i;
	return (token);
}
