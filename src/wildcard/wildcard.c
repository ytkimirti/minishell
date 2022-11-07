#include "wildcard.h"
#include "vector.h"


static char	**find_matches(char *str, int len);
static char	**search_nodes(char *source, char *pattern, int len_pattern);

// logs/*-12-1999/*.log
char	**expand_wildcard(t_token *token)
{
	char	**matches;
	char	*workdir;

	// read current working directory. if token starts with root dir. then override workdir.
	matches = search_nodes(workdir, token->str, token->len);
	return (matches);
}
