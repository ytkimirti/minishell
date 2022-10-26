/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/24 10:57:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "../libft/libft.h"

/*
 * Tokenizes a space just to seperate the tokens. For
 * example:
 * echo "Hello" "Boi"heh
 *
 * These will get tokenized like
 * Hello
 * Boi
 * heh
 *
 * But there is no way to know whether they are
 * seperated or joined.
 *
 * Note that the space must not be in a quote.
 * */
t_token	*tokenize_space(char **str, t_state *state)
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
