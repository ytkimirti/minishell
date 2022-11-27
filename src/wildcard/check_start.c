/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:59:18 by emakas            #+#    #+#             */
/*   Updated: 2022/11/26 14:22:05 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"

int	check_start(char *str, char *pattern)
{
	int index;

	index = 0;
	if (!pattern)
		return (1);
	while (*pattern != '*')
	{
		if (str[index] != *pattern)
			return (0);
		index++;
		pattern++;
	}
	return (1);
}