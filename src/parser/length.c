/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:42:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/08 15:02:36 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include <stdlib.h>
#include "parser_utils.h"
#include <assert.h>

/*
 * Length of the wildcard token should not be calculated here since it will
 * not be stringified like other tokens. It's just a seperator.
 */
int	length_token(t_token *token)
{
	assert(token->type != WILDCARD_TOKEN);
	if (token->type == WORD)
		return (token->len);
	if (token->type == VAR)
		return (get_env_length(token->str, token->len));
	return (0);
}

int	length_tokens(t_token **tokens)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (is_command_token(tokens[i]) && (tokens[i])->type != SPACE_TOKEN
		&& !is_redir_token(tokens[i]))
	{
		len += length_token(tokens[i]);
		i++;
	}
	return (len);
}
