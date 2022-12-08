/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:25:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/08 15:49:50 by ykimirti         ###   ########.tr       */
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
		&& !is_redir_token(**tokens) && (**tokens)->type != WILDCARD_TOKEN)
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

/*
 * TODO: Add the actual wildcard expansion to here
 */
char	*expand_wildcard_argument(t_token ***tokens)
{
	t_pvec	*list;

	list = pvec_new(5);
	while (true)
	{
		while (**tokens != NULL && (**tokens)->type == WILDCARD_TOKEN)
			(*tokens)++;
		if (!is_command_token(**tokens) || (**tokens)->type == SPACE_TOKEN)
			break ;
		pvec_append(list, expand_tokens(tokens));
		printf(">%s<\n", (char *)list->arr[list->len - 1]);
		while (**tokens != NULL && (**tokens)->type == WILDCARD_TOKEN)
			(*tokens)++;
		if (!is_command_token(**tokens) || (**tokens)->type == SPACE_TOKEN)
			break ;
	}
	free(list->arr);
	free(list);
	return (ft_strdup("<EXPANDED_WILDCARD>"));
}
