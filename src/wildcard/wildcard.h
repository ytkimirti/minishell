#ifndef WILDCARD_H
# define WILDCARD_H
# include "token.h"
# include "vector.h"

char	**expand_wildcard(t_token *token);
t_pvec	*search_nodes(char *source, char **patterns);
#endif