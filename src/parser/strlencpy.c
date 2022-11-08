/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlencpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:58 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 11:25:17 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Copies until it sees a NULL or reaches max_chars
 * Returns number of chars copied
 * If src is NULL returns 0
 */
int	strlencpy(char *dst, const char *src, int max_chars)
{
	int	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (i < max_chars && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}
