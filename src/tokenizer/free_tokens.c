/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:01:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 16:01:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
