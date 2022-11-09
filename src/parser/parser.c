/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/09 17:53:53 by ykimirti         ###   ########.tr       */
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
#include "coz.h"

/*
 * Expands token into string str.
 * Returns count of chars expanded
 */
static int	expand_token(t_token *token, char *str)
{
	COZ_PROGRESS;
	if (token->type == WORD)
		return (strlencpy(str, token->str, token->len));
	if (token->type == VAR)
		return (strlencpy(str, get_env(token->str, token->len), INT_MAX));
	return (0);
}

/*
 * Expands and joins tokens until it sees a space or
 * a non command token. Returns a string
 */
static char	*expand_tokens(t_token ***tokens)
{
	int		pos;
	char	*str;
	int		len;

	COZ_PROGRESS;
	len = length_tokens(*tokens);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	pos = 0;
	while (is_command_token(**tokens) && (**tokens)->type != SPACE)
	{
		pos += expand_token(**tokens, str + pos);
		(*tokens)++;
	}
	return (str);
}

// TODO: Add tokenizer fail here
static void	parse_redir(t_command *cmd, t_token ***tokens)
{
	char				*file;
	enum e_token_type	type;

	COZ_PROGRESS;
	type = (**tokens)->type;
	(*tokens)++;
	file = expand_tokens(tokens);
	if (type == REDIR_IN)
		cmd->in_file = file;
	else
	{
		cmd->out_file = file;
		cmd->is_append = type == REDIR_APPEND;
	}
}

void	parse_step(t_command *cmd, t_token ***tokens, t_pvec *args_vec)
{
	COZ_PROGRESS;
	if (is_redir_token(**tokens))
		parse_redir(cmd, tokens);
	else
		pvec_append(args_vec, expand_tokens(tokens));
}

t_command	*create_command(t_token ***tokens)
{
	t_command	*cmd;
	t_pvec		*args_vec;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (cmd == NULL)
		return (NULL);
	cmd->out_file = NULL;
	cmd->in_file = NULL;
	cmd->is_append = false;
	args_vec = pvec_new(16);
	while (is_command_token(**tokens))
	{
		skip_spaces(tokens);
		if (!is_command_token(**tokens))
			break ;
		parse_step(cmd, tokens, args_vec);
	}
	pvec_append(args_vec, NULL);
	cmd->argv = (char **)args_vec->arr;
	cmd->argc = args_vec->len - 1;
	free(args_vec);
	COZ_PROGRESS;
	return (cmd);
}
