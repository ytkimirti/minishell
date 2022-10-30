/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 20:36:14 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <unistd.h>
#include "tokenizer_funcs.h"
#include "../libft/vector.h"
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

// Returns new malloced t_token
t_token	*tokenize_single(const char **str, t_state *state)
{
	if (state->in_squotes)
	{
		if (**str == '\'')
			return (tokenize_quote(str, state));
	}
	else if (state->in_quotes)
	{
		if (**str == '"')
			return (tokenize_quote(str, state));
		else if (**str == '$')
			return (tokenize_var(str, state));
	}
	else
	{
		if (**str == ' ' || **str == '\t')
			return (tokenize_space(str, state));
		else if (**str == '$')
			return (tokenize_var(str, state));
		else if (**str == '"' || **str == '\'')
			return (tokenize_quote(str, state));
	}
	return (tokenize_word(str, state));
	return (NULL);
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
		return (NULL);
	while (*str != '\0')
	{
		token = tokenize_single(&str, &state);
		if (token == NULL)
			return (NULL);
		pvec_append(tokens, token);
	}
	pvec_append(tokens, NULL);
	tmp = (t_token **)tokens->arr;
	free(tokens);
	return (tmp);
}

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
