/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/31 09:37:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "token.h"
#include "utils.h"
#include <assert.h>
#include "parser_utils.h"
#include "libft.h"
#include "vector.h"

/*
 * Expands token into string str. Returns chars
 * expanded
 */
int	expand_token(t_token *token, char *str)
{
	if (token->type == WORD)
	{
		ft_memcpy(str, token->str, token->len);
		return (token->len);
	}
	return (0);
}

// If returns null, it means that it's the end of the command.
// For example when it sees a bracket or pipe token
char	*expand_tokens(t_token ***tokens_ref)
{
	t_token	**tokens;
	int		i;
	int		pos;
	char	*str;

	tokens = *tokens_ref;
	str = (char *)malloc(sizeof(char) * length_tokens(tokens));
	i = 0;
	pos = 0;
	while (tokens[i] != NULL && tokens[i]->type != SPACE)
	{
		pos += expand_token(tokens[i], str + pos);
		i++;
	}
	*tokens_ref = tokens + i;
	return (str);
}

void	expand_all_args(t_command *cmd, t_token ***tokens_ref)
{
	char	*arg;
	t_pvec	*args_vec;
	t_token	**tokens;

	tokens = *tokens_ref;
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
	*tokens_ref = tokens;
}

t_command	*create_command(t_token ***tokens)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (cmd == NULL)
		return (NULL);
	expand_all_args(cmd, tokens);
	return (cmd);
}
