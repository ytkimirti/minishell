/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/11 08:28:24 by ykimirti         ###   ########.tr       */
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
#include "error.h"

// TODO: Add tokenizer fail here
static bool	parse_redir(t_command *cmd, t_token ***tokens)
{
	char				*file;
	enum e_token_type	type;

	type = (**tokens)->type;
	(*tokens)++;
	if (type == REDIR_IN && cmd->in_file != NULL)
		return (error_false("Cannot have multiple inputs"));
	skip_spaces(tokens);
	if (!is_command_token(**tokens))
	{
		error_unexpected(**tokens, EMPTY);
		return (false);
	}
	file = expand_tokens(tokens);
	if (type == REDIR_IN)
		cmd->in_file = file;
	else
	{
		cmd->out_file = file;
		cmd->is_append = type == REDIR_APPEND;
	}
	return (true);
}

bool	parse_step(t_command *cmd, t_token ***tokens, t_pvec *args_vec)
{
	char	*str;

	if (is_redir_token(**tokens))
		return (parse_redir(cmd, tokens));
	str = expand_tokens(tokens);
	if (str == NULL)
		return (false);
	pvec_append(args_vec, str);
	return (true);
}

void	*panic_free(t_command *cmd, t_pvec *args_vec)
{
	if (cmd->in_file != NULL)
		free(cmd->in_file);
	if (cmd->out_file != NULL)
		free(cmd->out_file);
	free(cmd);
	pvec_del(args_vec, free);
	return (NULL);
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
		if (!parse_step(cmd, tokens, args_vec))
			return (panic_free(cmd, args_vec));
	}
	pvec_append(args_vec, NULL);
	cmd->argv = (char **)args_vec->arr;
	cmd->argc = args_vec->len - 1;
	free(args_vec);
	return (cmd);
}
