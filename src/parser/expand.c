/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:13:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 07:27:44 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "parser_utils.h"
#include "libft.h"
#include "vector.h"

#if 0

// If returns null, it means that it's the end of the command.
// For example when it sees a bracket or pipe token
char	*expand_tokens(t_token ***tokens_ref)
{
	t_token	**tokens;
	int		i;
	char	*str;

	i = 0;
	tokens = *tokens_ref;
	assert(*tokens != NULL && tokens[0]->type != SPACE);
	while (tokens[i] != NULL && tokens[i]->type != SPACE)
		i++;
	str = (char *)malloc(sizeof(char) * calculate_length(tokens));
	free(str);
	*tokens_ref = tokens + i;
	return (ft_strdup("dummy"));
}

void	expand_all_args(t_cmd *cmd, t_token **tokens)
{
	char	*arg;
	t_pvec	*args_vec;

	args_vec = pvec_new(16);
	while (*tokens != NULL)
	{
		while (*tokens != NULL && (*tokens)->type == SPACE)
			tokens++;
		arg = expand_tokens(&tokens);
		if (arg == NULL)
			break ;
		pvec_append(args_vec, arg);
	}
	pvec_append(args_vec, NULL);
	cmd->argv = (char **)args_vec->arr;
	cmd->argc = args_vec->len - 1;
	free(args_vec);
}

#endif
