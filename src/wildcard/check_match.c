/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:42 by emakas            #+#    #+#             */
/*   Updated: 2022/12/22 15:26:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "wildcard.h"
#include "libft.h"
#include "error.h"

static int	strncmp2(const char *str, const char *search)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0' && search[index] != '\0')
	{
		if (compare_char(search[index], str[index]) != 0)
			return (str[index] - search[index]);
		index++;
	}
	if (search[index] == '\0')
		return (0);
	return (str[index] - search[index]);
}

static char	*strnstr2(const char *str, const char *search)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (strncmp2(&str[index], search) == 0)
			return ((char *) &str[index]);
		index++;
	}
	return (NULL);
}

/*
 * Checks is str contains all the strings `contains`
 * in order in it.
 */
static bool	check_inside(char *str, char **contains)
{
	char	*candidate;
	int		index;

	candidate = str;
	index = 0;
	while (contains[index] != NULL && *candidate)
	{
		candidate = strnstr2(candidate, contains[index]);
		if (candidate == NULL)
			return (false);
		candidate += ft_strlen(contains[index]);
		index++;
	}
	return (true);
}

/*
 * Checks if the start and end of the str work with pattern
 */
static int	check_edges(char *str, char *pattern)
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

/*
 * *aaa*bb*cc*
 * aaa
 * bb
 * cc
 */
int	check_match(char *str, char *pattern)
{
	char	**patterns_split;
	bool	found;

	patterns_split = ft_split(pattern, '*');
	if (patterns_split == NULL)
		malloc_error();
	if (check_edges(str, pattern)
		&& check_inside(str, patterns_split))
		found = true;
	else
		found = false;
	free_array(patterns_split);
	return (found);
}
