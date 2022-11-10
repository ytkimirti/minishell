/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:53:32 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 19:07:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_utils.h"
#include <stdlib.h>
#include "error.h"
#include "parser.h"

t_node	*primary_paren(t_token ***tokens)
{
	t_node	*inside;

	(*tokens)++;
	inside = expr(tokens);
	if (inside == NULL)
		return (NULL);
	if (**tokens == NULL || (**tokens)->type != PAREN_CLOSE)
	{
		error_unexpected(**tokens, PAREN_CLOSE);
		return (NULL);
	}
	(*tokens)++;
	while (**tokens != NULL && (**tokens)->type == SPACE)
		(*tokens)++;
	return (inside);
}

t_node	*primary_command(t_token ***tokens)
{
	t_command	*cmd;

	cmd = create_command(tokens);
	if (cmd == NULL)
		return (NULL);
	return (wrap_command(cmd));
}
