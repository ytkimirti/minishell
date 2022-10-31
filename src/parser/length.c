/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:42:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 23:43:26 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdlib.h>

int	length_token(t_token *token)
{
	if (token->type == WORD)
		return (token->len);
	return (0);
}

int	length_tokens(t_token **tokens)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (tokens[i] != NULL && tokens[i]->type != SPACE)
	{
		len += length_token(tokens[i]);
		i++;
	}
	return (len);
}
