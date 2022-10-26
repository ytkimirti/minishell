/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/10 22:45:57 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer.h"

char	*dup_token_str(t_token *token)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (token->len + 1));
	ft_memcpy(str, token->str, token->len);
	str[token->len] = '\0';
	return (str);
}
