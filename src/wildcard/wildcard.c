#include "wildcard.h"
#include "vector.h"


static char	**find_matches(char *str, int len);

static int	compare_pattern(char *source, char *pattern, int len_pattern);

static char	**search_nodes(char *source, char *pattern, int len_pattern);

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
 * @return char**
 */
static char **search_nodes(char *source, char *pattern, int len_pattern)
{
	char	*pattern;
	char	*next_pattern;
	t_cvec	*matches;

	matches = cvec_new(2);

	

}
