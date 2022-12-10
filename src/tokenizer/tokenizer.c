/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/09 20:39:47 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <unistd.h>
#include "error.h"
#include "tokenizer_funcs.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "tokenize_utils.h"

t_token	*tokenize_outside(const char **str, t_state *state)
{
	if (**str == ' ' || **str == '\t')
		return (tokenize_space(str, state));
	else if (**str == '$')
		return (tokenize_var(str, state));
	else if (**str == '"' || **str == '\'')
		return (tokenize_quote(str, state));
	else if ((**str == '&' && (*str)[1] == '&')
			|| (**str == '|' && (*str)[1] == '|'))
		return (tokenize_control(str, state));
	else if (**str == '|')
		return (tokenize_pipe(str, state));
	else if (**str == '(' || **str == ')')
		return (tokenize_paren(str, state));
	else if (**str == '>' || **str == '<')
		return (tokenize_redir(str, state));
	else if (**str == '*' || **str == '?')
		return (tokenize_wildcard(str, state));
	else
		return (tokenize_word(str, state));
}

t_token	*tokenize_in_squotes(const char **str, t_state *state)
{
	if (**str == '\'')
		return (tokenize_quote(str, state));
	else
		return (tokenize_word(str, state));
}

t_token	*tokenize_in_quotes(const char **str, t_state *state)
{
	if (**str == '"')
		return (tokenize_quote(str, state));
	else if (**str == '$')
		return (tokenize_var(str, state));
	else
		return (tokenize_word(str, state));
}

t_token	*tokenize_single(const char **str, t_state *state)
{
	if (state->in_squotes)
		return (tokenize_in_squotes(str, state));
	else if (state->in_quotes)
		return (tokenize_in_quotes(str, state));
	else
		return (tokenize_outside(str, state));
}

t_token	**tokenize(const char *str)
{
	t_token	*token;
	t_pvec	*tokens;
	t_token	**tmp;
	t_state	state;

	state.in_quotes = false;
	state.in_squotes = false;
	tokens = pvec_new(32);
	if (tokens == NULL)
		malloc_error();
	while (*str != '\0')
	{
		token = tokenize_single(&str, &state);
		if (token == NULL)
			break ;
		pvec_append(tokens, token);
	}
	pvec_append(tokens, NULL);
	tmp = (t_token **)tokens->arr;
	free(tokens);
	return (tmp);
}
