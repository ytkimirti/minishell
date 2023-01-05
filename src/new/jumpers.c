/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:40:04 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/05 19:30:03 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <assert.h>
#include "new.h"
#include <unistd.h>
#include "parser_utils.h"

t_token	**jump_paren(t_token **tokens)
{
	int	depth;

	if (*tokens == NULL)
		return (tokens);
	depth = 0;
	while (*tokens != NULL)
	{
		if ((*tokens)->type == PAREN_OPEN)
			depth++;
		if ((*tokens)->type == PAREN_CLOSE)
			depth--;
		if (depth == 0)
			return (tokens);
		tokens++;
	}
	return (tokens);
}

t_token	**jump_primary(t_token **tokens)
{
	skip_spaces(&tokens);
	if (*tokens == NULL)
		return (tokens);
	if ((*tokens)->type == PAREN_OPEN)
	{
		tokens = jump_paren(tokens) + 1;
		skip_spaces(&tokens);
	}
	else
	{
		while (is_command_token(*tokens))
			tokens++;
	}
	return (tokens);
}

/*
 * Jumps one primary and one pipe character.
 * Since the first and last is primary, does
 * it does skip whitespaces
 */
t_token	**jump_pipeline(t_token **tokens)
{
	while (true)
	{
		tokens = jump_primary(tokens);
		if (*tokens == NULL)
			return (tokens);
		if ((*tokens)->type != PIPE_TOKEN)
			return (tokens);
		tokens++;
	}
	return (tokens);
}

t_token	**jump_to_end(t_token **tokens)
{
	while ((*tokens) != NULL)
		tokens++;
	return (tokens);
}
