/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:27:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/08 13:23:39 by ykimirti         ###   ########.tr       */
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

/*
 * TODO: Make tokenizing a word a non freeable pointer thing.
 * Make it a pointer to the thing inside str.
 */
t_token	*tokenize_word(char **str, t_state *state)
{
	t_token	*token;
	int		i;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = WORD;
	i = 0;
	while ((*str)[i] != '\0'
		&& ((state->in_quotes && (*str)[i] != '$' && (*str)[i] != '"')
			|| (!state->in_quotes && !is_metacharacter((*str)[i]))
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
