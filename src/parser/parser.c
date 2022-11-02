/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 16:32:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "token.h"
#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include "parser_utils.h"
#include "libft.h"
#include "vector.h"
#include "env.h"
#include <limits.h>

/*
 * Copies until it sees a NULL or reaches max_chars
 * Returns number of chars copied
 * If src is NULL returns 0
 */
static int	strlencpy(char *dst, const char *src, int max_chars)
{
	int	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (i < max_chars && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

/*
 * Expands token into string str. Returns chars
 * expanded
 */
int	expand_token(t_token *token, char *str)
{
	if (token->type == WORD)
		return (strlencpy(str, token->str, token->len));
	if (token->type == VAR)
		return (strlencpy(str, get_env(token->str, token->len), INT_MAX));
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
	int		len;

	tokens = *tokens_ref;
	len = length_tokens(tokens);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	pos = 0;
	while (is_command_token(tokens[i]) && tokens[i]->type != SPACE)
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
	while (is_command_token(*tokens))
	{
		while (is_command_token(*tokens) && (*tokens)->type == SPACE)
			tokens++;
		if (!is_command_token(*tokens))
			break ;
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
	cmd->redir_file = NULL;
	return (cmd);
}
