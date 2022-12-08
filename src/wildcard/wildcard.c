/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:08:45 by emakas            #+#    #+#             */
/*   Updated: 2022/12/07 14:59:51 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"
#include "error.h"
#include "wildcard_utils.h"
#include "vector.h"
#include "utils.h"
#include <libft.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

t_pvec		*search_nodes(char *source, char **patterns);

static char	*concat_dir(char *dir1, char *dir2);

static void	free_array(char **array)
{
	char	**p;

	p = array;
	while (*p != NULL)
	{
		free(*p);
		p++;
	}
	free(array);
}

static void	dig_in_dir(char *source, char *d_name,
				char **patterns, t_pvec *matches);

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
t_pvec	*search_nodes(char *source, char **patterns)
{
	struct dirent	*entry;
	t_pvec			*matches;
	DIR				*dir;

	matches = pvec_new(5);
	dir = opendir(source);
	if (dir == NULL)
		return (perror("opendir error"), NULL);
	entry = readdir(dir);
	while (entry != NULL && dir != NULL)
	{
		if (ft_strncmp(entry->d_name, ".", sizeof(".")) != 0
			&& ft_strncmp(entry->d_name, "..", sizeof("..")) != 0
			&& check_match(entry->d_name, patterns[0]))
		{
			if (patterns[1] != NULL && entry->d_type == DT_DIR)
				dig_in_dir(source, entry->d_name, &patterns[1], matches);
			else if (patterns[1] == NULL)
				pvec_append(matches, concat_dir(source, entry->d_name));
		}
		entry = readdir(dir);
	}
	closedir(dir);
	pvec_append(matches, NULL);
	return (matches);
}

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

	if (token == NULL)
		return (NULL);
	if (token->str[0] == '/')
		source = "/";
	else
		source = ".";
	pattern = dup_token_str(token);
	if (pattern == NULL)
		malloc_error();
	patterns = ft_split(pattern, '/');
	if (patterns == NULL)
		malloc_error();
	match_vector = search_nodes(source, patterns);
	matches = (char **) match_vector->arr;
	free(match_vector);
	free(pattern);
	free_array(patterns);
	return (matches);
}

static void	dig_in_dir(char *source,
		char *d_name,
		char **patterns, t_pvec *matches)
{
	char	*source_new;
	t_pvec	*pvec;

	source_new = concat_dir(source, d_name);
	pvec = search_nodes(source_new, patterns);
	if (pvec->len > 0)
		vector_append_all(matches, pvec);
	free(pvec->arr);
	free(pvec);
	free(source_new);
}

static char	*concat_dir(char *dir1, char *dir2)
{
	char	*result;
	size_t	len;
	size_t	index;

	if (ft_strncmp(dir1,".",ft_strlen(dir1)) == 0)
		return (ft_strdup(dir2));
	index = 0;
	len = ft_strlen(dir1) + ft_strlen(dir2) + 2;
	result = malloc(sizeof(char) * len);
	while (*dir1 != '\0')
		result[index++] = *(dir1++);
	result[index++] = '/';
	while (*dir2 != '\0')
		result[index++] = *(dir2++);
	result[index] = '\0';
	return (result);
}