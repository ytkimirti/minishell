/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/08 18:27:18 by ykimirti         ###   ########.tr       */
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
t_token	*tokenize_single(char **str, t_state *state)
{
	t_token	*token;

	if (**str == ' ' || **str == '\t')
		token = tokenize_space(str, state);
	else if (**str == '$')
		token = tokenize_var(str, state);
	else
		token = tokenize_word(str, state);
	return (token);
}

t_token	**tokenize(char *str)
{
	t_token	*token;
	t_pvec	*tokens;
	t_token	**tmp;
	t_state	state;

	state.in_quotes = false;
	tokens = pvec_new(32);
	if (tokens == NULL)
		return (NULL);
	while (*str != '\0')
	{
		token = tokenize_single(&str, &state);
		if (token == NULL)
			return (NULL);
		print_token(token);
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
