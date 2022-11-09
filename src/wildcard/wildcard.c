#include "wildcard.h"
#include "vector.h"


static char	**find_matches(char *str, int len);
static char	**search_nodes(char *source, char *pattern, int len_pattern);

/*!
 * @brief Lists all matches of given wildcard
 *
 * Example wildcard is: "logs/ *-12-1999/ *.log"
 *
 * * First get into logs/ and search occurences for "logs"
 * * Assign occurences into MATCHES
 * * iterate to next pattern "*-12-1999"
 * * search each matches for each directories in previous MATCHES
 * * Assign MATCHES to new MATCHES
 *
 * @param token
 * @return char** List of all occurences
 */
char	**expand_wildcard(t_token *token)
{
	char	**matches;
	char	*pattern;
	int		index;
	int		index_new;
	// We need to iterate through slashes (/)
	// It is not that constraint but according to this algorithm.. yes it is.
	index = 0;
	while (index < token->len)
	{
		index_new = pattern_next(pattern); // finds next pattern 
		// do stuff
		// matches = search_nodes(?,pattern,index_new - index);
		index = index_new;
	}
	return (matches);
}
