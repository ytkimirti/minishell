/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:21:55 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 13:17:32 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/colors.h"
#include "token.h"
#include "utils.h"
#include <stdio.h>

char	*token_type_tostr2(enum e_token_type type)
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

void	print_token(t_token *token)
{
	char	*token_str;

	printf("(t_token) { "
		".type = " MAG "%s" RST,
		token_type_tostr(token->type));
	if (token->str != NULL && is_printable(token->type))
	{
		token_str = dup_token_str(token);
		printf(", .len = " MAG "%d" RST ", "
			".str = " YEL "\"%s\" " RST,
			token->len, token_str);
		free(token_str);
	}
	printf("}\n");
}

void	print_tokens(t_token **tokens)
{
	while (*tokens != NULL)
	{
		print_token(*tokens);
		tokens++;
	}
}
