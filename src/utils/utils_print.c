/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:21:55 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 19:15:41 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "token.h"
#include "utils.h"
#include <stdio.h>

static char	*token_type_tostr2(enum e_token_type type)
{
	if (type == AND_TOKEN)
		return ("AND_TOKEN");
	if (type == OR_TOKEN)
		return ("OR_TOKEN");
	if (type == PIPE_TOKEN)
		return ("PIPE_TOKEN");
	if (type == REDIR_IN)
		return ("REDIR_IN");
	if (type == REDIR_OUT)
		return ("REDIR_OUT");
	if (type == REDIR_APPEND)
		return ("REDIR_APPEND");
	return ("UNKNOWN");
}

// Returns a non freeable string constant
char	*token_type_tostr(enum e_token_type type)
{
	if (type == WORD)
		return ("WORD");
	if (type == SPACE)
		return ("SPACE");
	if (type == DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	if (type == SINGLE_QUOTE)
		return ("SINGLE_QUOTE");
	if (type == PAREN_OPEN)
		return ("PAREN_OPEN");
	if (type == PAREN_CLOSE)
		return ("PAREN_CLOSE");
	if (type == EMPTY)
		return ("EMPTY");
	if (type == VAR)
		return ("VAR");
	return (token_type_tostr2(type));
}

char	*token_type_repr(t_token_type type)
{
	if (type == DOUBLE_QUOTE)
		return ("\"");
	if (type == SINGLE_QUOTE)
		return ("\'");
	if (type == PAREN_OPEN)
		return ("(");
	if (type == PAREN_CLOSE)
		return (")");
	if (type == REDIR_IN)
		return ("<");
	if (type == REDIR_OUT)
		return (">");
	if (type == REDIR_APPEND)
		return (">>");
	if (type == AND_TOKEN)
		return ("&&");
	if (type == OR_TOKEN)
		return ("||");
	if (type == PIPE_TOKEN)
		return ("|");
	return (token_type_tostr(type));
}
