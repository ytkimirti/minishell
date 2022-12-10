/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:59:18 by emakas            #+#    #+#             */
/*   Updated: 2022/12/10 16:48:01 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "libft.h"

int	check_end(char *str, char *pattern)
{
	int	index;
	int	index_pattern;

	index = ft_strlen(str);
	index_pattern = ft_strlen(pattern);
	if (!pattern)
		return (1);
	while (pattern[index_pattern] != '*' && index >= 0 && index_pattern >= 0)
	{
		if (compare_char(pattern[index_pattern], str[index]) != 0)
			return (0);
		index--;
		index_pattern--;
	}
	return (1);
}
