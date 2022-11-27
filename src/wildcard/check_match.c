/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:42 by emakas            #+#    #+#             */
/*   Updated: 2022/11/26 23:01:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "wildcard.h"
#include "libft.h"

static int check_edges(char *str, char *contains);
static int	check_inside(char *str, char **contains);

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
	return (0);
}

static int check_inside(char *str, char **contains)
{
	char	*candidate;
	int		index;

	candidate = str;
	index = 0;
	while (contains && contains[index] != NULL && *candidate)
	{
		candidate = ft_strnstr(candidate,contains[index],ft_strlen(candidate));
		if (candidate == NULL)
			return (0);
		candidate += ft_strlen(contains[index]);
		index++;
	}
	return (1);
}

static int check_edges(char *str, char *pattern)
{

	if (pattern)
	{
		if (check_start(str, pattern) == 0)
			return (0);
		if (check_end(str, pattern) == 0)
			return (0);
	}
	return (1);
}
