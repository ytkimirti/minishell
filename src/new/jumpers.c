/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:40:04 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/15 16:26:56 by ykimirti         ###   ########.tr       */
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
	if ((*tokens)->type == PAREN_OPEN)
		return (jump_paren(tokens));
	while (*tokens != NULL && (is_command_token(*tokens)
			|| (*tokens)->type == SPACE_TOKEN))
		tokens++;
	return (tokens);
}

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
