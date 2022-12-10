/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:59:18 by emakas            #+#    #+#             */
/*   Updated: 2022/12/10 16:47:12 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"

int	check_start(char *str, char *pattern)
{
	int	index;

	index = 0;
	while (*pattern != '*' && *pattern != '\0')
	{
		if (compare_char(*pattern, str[index]) != 0)
			return (0);
		index++;
		pattern++;
	}
	if (*pattern == '\0' && str[index] != '\0')
		return (0);
	return (1);
}
