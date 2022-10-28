/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:33 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:25:42 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/vector.h"
#include "../libft/libft.h"

// Name as in bash variable name characters
inline static bool	is_name(char c)
{
	return (ft_isalpha(c) || c == '_');
}

inline static bool	is_special_var(char c)
{
	return (c == '?' || c == '#' || (c >= '0' && c <= '9'));
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
	if ((*str)[0] != '\0' && is_special_var((*str)[i]))
		i++;
	else
	{
		while (is_name((*str)[i]))
			i++;
	}
	token->type = VAR;
	token->str = *str;
	token->len = i;
	(*str) += i;
	return (token);
}
