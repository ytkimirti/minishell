/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:17:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 18:18:08 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "token.h"
#include "utils.h"
#include <stdio.h>

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
