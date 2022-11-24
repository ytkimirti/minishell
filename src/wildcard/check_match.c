/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:42 by emakas            #+#    #+#             */
/*   Updated: 2022/11/24 20:52:23 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "wildcard.h"
#include "libft.h"

static int check_edges(char *str, char **contains);
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
	return (-1);
}

static int check_inside(char *str, char **contains)
{
	char	*candidate;
	char	*founded;
	size_t	len_candidate;
	int		index;

	candidate = NULL;
	len_candidate = -1;
	founded = str;
	index = 0;
	while (contains && contains[index] != NULL)
	{
		founded = ft_strnstr(founded,contains[index],ft_strlen(founded));
		if (candidate == NULL || ((candidate + len_candidate) < founded))
			candidate = founded;
		else
			return (0);
		index++;
	}
	return (1);
}

static int count_array(char **arr)
{
	int	count;

	count = 0;
	while (arr && arr[count] != NULL)
		count++;
	return (count);
}

static int ft_strrstr(char *str, char *ending)
{
	size_t	len_ending;
	size_t	index;
	
	len_ending = ft_strlen(ending);
	index = ft_strlen(str);
	while (index >= 0)
	{
		if (ft_strncmp(str,ending,len_ending))
			return (1);
		index--;
	}
	return (0);
}

static int check_edges(char *str, char **contains)
{

	if (contains)
	{
		if (ft_strnstr(str,contains[0],ft_strlen(str)) > str)
			return (0);
		if (!ft_strrstr(str,contains[count_array(contains) - 1]))
			return (0);
	}
	return (1);
}
