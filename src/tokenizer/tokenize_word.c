/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/22 15:18:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "tokenize_utils.h"
#include "vector.h"
#include "libft.h"
#include "error.h"

// These functions will decide whether to stop or not
static bool	squotes_should_continue(const char *c)
{
	return (*c != '\'');
}

static bool	quotes_should_continue(const char *c)
{
	return (*c != '"' && !is_valid_var(c));
}

static bool	outside_should_continue(const char *c)
{
	if (*c == '$')
		return (!is_valid_var(c));
	return (!is_metacharacter(*c));
}

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
		&& ((state->in_squotes && squotes_should_continue(*str + i))
			|| (state->in_quotes && quotes_should_continue(*str + i))
			|| (!state->in_quotes && !state->in_squotes
				&& outside_should_continue(*str + i))
			)
		)
		i++;
	token->str = *str;
	token->len = i;
	(*str) += i;
	return (token);
}
