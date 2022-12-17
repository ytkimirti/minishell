/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:33 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/17 20:20:14 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "vector.h"
#include "libft.h"
#include "error.h"

// Name as in bash variable name characters
bool	is_valid_var_name(char c)
{
	return (ft_isalpha(c) || c == '_');
}


inline static bool	is_special_var(char c)
{
	return (c == '?' || c == '#' || (c >= '0' && c <= '9'));
}

bool is_valid_var(const char *str)
{
	char next_char = str[1];
	return (str[0] == '$' && (is_valid_var_name(next_char) || is_special_var(next_char)));
}

t_token	*tokenize_var(char **str, t_state *state)
{
	t_token	*token;
	int		i;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	(*str)++;
	i = 0;
	if ((*str)[0] != '\0' && is_special_var((*str)[i]))
		i++;
	else
	{
		while (is_valid_var_name((*str)[i]))
			i++;
	}
	token->type = VAR;
	token->str = *str;
	token->len = i;
	(*str) += i;
	return (token);
}
