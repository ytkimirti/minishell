/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:08:45 by emakas            #+#    #+#             */
/*   Updated: 2022/11/13 15:29:34 by emakas           ###   ########.fr       */
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

static t_pvec	*search_nodes(char *source, char *pattern, int len_pattern);

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
	char	*pattern;
	char	*source;
	int		*pattern_len;

	match_vector = search_nodes(source, pattern, pattern_len);
	matches = (char **) match_vector->arr;
	free(match_vector);
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
static t_pvec	*search_nodes(char *source, char *pattern, size_t len_pattern)
{
	struct dirent	*entry;
	t_pvec			*matches;
	char			*next_pattern;
	size_t			*len_next_pattern
	DIR				*dir;

	matches = pvec_new(1);
	next_pattern = ft_strnstr(pattern, "/", len_pattern) + 1;
	len_next_pattern = len_pattern - (next_pattern - pattern);
	dir = opendir(source);
	if (dir == NULL)
		return (matches);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (check_match(entry->d_name, pattern))
		{
			if (len_next_pattern > 0)
				append_all(matches, recurse(source,
					entry->d_name,next_pattern,len_next_pattern));
			else
				append_vector(matches,source,entry->d_name);
		}
		entry = readdir(dir);
	}
	return (matches);
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