/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 16:26:41 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/vector.h"
#include "../libft/libft.h"

bool	is_metacharacter(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '<'
		|| c == '>'
		|| c == '('
		|| c == ')'
		|| c == '&'
		|| c == '|');
}

/*
 * Tokenizes a word until;
 * 	if in a quote, until it sees $,
 * 	otherwise until it sees a metacharacter
 * */
t_token	*tokenize_word(char **str, t_state *state)
{
	t_cvec	*vec;
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	vec = cvec_new(64);
	if (!vec)
		return (NULL);
	token->type = WORD;
	while (**str != '\0'
		&& ((state->in_quotes && **str != '$')
			|| (!state->in_quotes && !is_metacharacter(**str))))
	{
		cvec_append(vec, **str);
		(*str)++;
	}
	token->str = vec->arr;
	token->len = vec->len;
	free(vec);
	return (token);
}
