/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:21 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/13 17:22:42 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include "parser_utils.h"
#include "libft.h"
#include "vector.h"
#include "env.h"
#include <limits.h>
#include "error.h"
#include "wildcard.h"

/*
 * Expands token into string str.
 * Returns count of chars expanded
 */
static int	expand_token(t_token *token, char *str)
{
	if (token->type == WORD)
		return (strlencpy(str, token->str, token->len));
	if (token->type == VAR)
		return (strlencpy(str, get_env(token->str, token->len), INT_MAX));
	return (0);
}

typedef struct s_expand_state
{
	bool	in_squote;
	bool	in_quote;
}	t_expand_state;

static void	update_expand_state(t_expand_state *state, t_token_type type)
{
	if (type == SINGLE_QUOTE)
		state->in_squote = !state->in_squote;
	if (type == DOUBLE_QUOTE)
		state->in_quote = !state->in_quote;
}

char	*expand_tokens(t_token ***tokens)
{
	int				pos;
	char			*str;
	int				len;
	t_expand_state	state;

	len = length_tokens(*tokens);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	pos = 0;
	state = (t_expand_state){false, false};
	while (is_command_token(**tokens) && (**tokens)->type != SPACE_TOKEN
		&& !is_redir_token(**tokens) && !is_wildcard_token(**tokens))
	{
		update_expand_state(&state, (**tokens)->type);
		pos += expand_token(**tokens, str + pos);
		(*tokens)++;
	}
	if (!state.in_quote && !state.in_squote)
		return (str);
	if (state.in_squote)
		error_unexpected(**tokens, SINGLE_QUOTE);
	else if (state.in_quote)
		error_unexpected(**tokens, DOUBLE_QUOTE);
	free(str);
	return (NULL);
}
