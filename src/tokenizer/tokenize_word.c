/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:11:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "tokenize_utils.h"
#include "vector.h"
#include "libft.h"
#include "error.h"

t_token	*tokenize_word(const char **str, t_state *state)
{
	t_token	*token;
	int		i;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	token->type = WORD;
	i = 0;
	while ((*str)[i] != '\0'
		&& ((state->in_squotes && (*str)[i] != '\'')
			|| (state->in_quotes && (*str)[i] != '"' && (*str)[i] != '$')
			|| (!is_metacharacter((*str)[i]))
			)
		)
	{
		i++;
	}
	token->str = *str;
	token->len = i;
	(*str) += i;
	return (token);
}
