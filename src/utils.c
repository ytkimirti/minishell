/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/06 11:26:42 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tokenizer.h"

// Duplicate the str inside token
// and null terminate it
char	*dup_token_str(t_token *token)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (token->len + 1));
	ft_memcpy(str, token->str, token->len);
	str[token->len] = '\0';
	return (str);
}
