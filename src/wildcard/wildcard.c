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
 * * if "logs" is a folder (it is) search next pattern matches
 *   "*-12-1999" inside the matched folders for "logs"
 *
 * @param token
 * @return char** List of all occurences
 */
char	**expand_wildcard(t_token *token)
{
	char	**matches;
	int		index;
	// We need to iterate through slashes (/)
	index = 0;
	while (index < token->len)
	{
		// do stuff
		index = pattern_next(token->str); // finds next pattern 
	}
	return (matches);
}
