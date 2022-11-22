/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:42 by emakas            #+#    #+#             */
/*   Updated: 2022/11/22 18:48:07 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "wildcard.h"
#include "libft.h"

static int check_edges(char *str, char *pattern);
static int	check_inside(char *str, char **patterns);

int	check_match(char *str, char *pattern)
{
	char	**patterns_split;

	patterns_split = ft_split(pattern,'*');
	if (str == NULL || pattern == NULL)
		return (-1);
	if (check_edges(str, pattern))
	{
		if (check_inside(str, patterns_split))
			return (1);
	}
	return (-1);
}