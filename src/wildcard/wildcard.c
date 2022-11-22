/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:08:45 by emakas            #+#    #+#             */
/*   Updated: 2022/11/22 14:44:18 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"
#include "vector.h"
#include <libft.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

static char		**find_matches(char *str, int len);

static int		compare_pattern(char *source, char *pattern, int len_pattern);

static t_pvec	*search_nodes(char *source, char **patterns);

static int		check_match(char *source, char *pattern);

static t_pvec	*recurse(char *source, char *dir, char *pattern, size_t len_p);

/*!
 * @brief Lists all matches of given wildcard
 *
 * Example wildcard is: "logs/ *-12-1999/ *.log"
 *
 *
 * @param token
 * @return char** List of all occurences
 */
char	**expand_wildcard(t_token *token)
{
	t_pvec	*match_vector;
	char	**matches;
	char	**patterns;
	char	*source;
	char	*pattern;

	// set up source directory...
	pattern  = dup_token_str(token);
	patterns = ft_split(pattern,"/");
	match_vector = search_nodes(source, patterns);
	matches = (char **) match_vector->arr;
	free(match_vector);
	free(pattern);
	return (matches);

	
}

/**
 * @brief Searches pattern and returns matches
 *
 * This function is recursive.
 *
 * * First get into logs/ and search occurences for "logs"
 * * Assign occurences into MATCHES
 * * iterate to next pattern "*-12-1999"
 * * search each matches for each directories in previous MATCHES
 * * Assign MATCHES to new MATCHES
 *
 * @param source
 * @param pattern
 * @param len_pattern
 * @return t_pvec * char array vector
 */
static t_pvec	*search_nodes(char *source, char **patterns)
{
	struct dirent	*entry;
	t_pvec			*matches;
	DIR				*dir;

	matches = pvec_new(1);
	dir = opendir(source);
	if (dir == NULL)
		return (matches);
	entry = readdir(dir);
	while (entry != NULL)
	{
		//TODO: Solve free malloc problem for source
		if (check_match(entry->d_name, patterns[0]))
		{
			if (patterns[1] != NULL)
				vector_append_all(matches,search_nodes(
					concat_dir(source, patterns[0]), &patterns[1]));
			else
				pvec_append(matches, concat_dir(source, entry->d_name));
		}
		entry = readdir(dir);
	}
	closedir(source);
	free(source);
	return (matches);
}

static int	check_match(char *source, char *pattern)
{
	return (0);
}

static char	*concat_dir(char *dir1, char *dir2)
{
	char	*result;
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(dir1) + ft_strlen(dir2) + 2;
	result = malloc(sizeof (char) *len);
	while (*dir1 != '\0')
		result[index++] = *(dir1++);
	result[index++] = "/";
	while (*dir2 != '\0')
		result[index++] = *(dir2++);
	result[index] = '\0';
	return (result);
}
/*

def search(pattern,source):
	matches = list()
	while ((dir = readdir(source) != NULL)
		if (checkk_match(dir->name,pattern_first):
			if (next_pattern != NULL):
				matches.addAll(search(next_pattern,source + dir->name));
			else:
				matches.add(dir->name)
	return matches
			


*/