/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:55 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "tokenizer.h"

char	*dup_token_str(t_token *token)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (token->len + 1));
	if (!str)
		malloc_error();
	ft_memcpy(str, token->str, token->len);
	str[token->len] = '\0';
	return (str);
}
