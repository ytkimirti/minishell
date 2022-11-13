#include "wildcard.h"
#include "vector.h"
#include <libft.h>
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>

static char	**find_matches(char *str, int len);

static int	compare_pattern(char *source, char *pattern, int len_pattern);

static t_pvec *search_nodes(char *source, char *pattern, int len_pattern);

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
	char	**matches;
	char	*pattern;
	char	*source; // absolute path prefix. If relative path given, this source prefixes before pattern
	int		*pattern_len; // length of pattern;
	
	matches = search_nodes(source, pattern, pattern_len);

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
static t_pvec *search_nodes(char *source, char *pattern, int len_pattern)
{
	struct dirent	*entry
	t_pvec			*matches;
	char			*next_pattern;
	DIR				*dir;
	
	matches = pvec_new(1);
	next_pattern = ft_strnstr(pattern,"/",len_pattern);
	dir = opendir(source);
	if (dir == NULL)
		return (NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		if (check_match(entry->d_name, pattern))
		{
			if (next_pattern != NULL)
				recurse(source,entry->d_name,next_pattern,len);
		}
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