/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 20:03:15 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
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

// Creates a new redir object,
// fills it up by expanding the word,
// appends it to the redirs_vec
// moves the tokens pointer of course...
static bool	parse_redir(t_token ***tokens, t_pvec *redirs_vec)
{
	t_redir				*redir;

	redir = malloc(sizeof(t_redir));
	redir->type = (**tokens)->type;
	(*tokens)++;
	skip_spaces(tokens);
	if (!is_command_token(**tokens))
	{
		free(redir);
		error_unexpected(**tokens, EMPTY);
		return (false);
	}
	redir->str = expand_tokens(tokens);
	pvec_append(redirs_vec, redir);
	return (true);
}

bool	parse_step(t_token ***tokens, t_pvec *args_vec
		, t_pvec *redirs_vec)
{
	char	*str;

	if (is_redir_token(**tokens))
		return (parse_redir(tokens, redirs_vec));
	if (is_wildcard_argument(*tokens))
		return (expand_wildcard_argument(tokens, args_vec));
	else
		str = expand_tokens(tokens);
	if (str == NULL)
		return (false);
	pvec_append(args_vec, str);
	return (true);
}

void	panic_free(t_command *cmd, t_pvec *args_vec, t_pvec *redirs_vec)
{
	free(cmd);
	pvec_del(args_vec, free);
	pvec_del(redirs_vec, free);
}

// ls "$USER" 
t_command	*create_command(t_token ***tokens)
{
	t_command	*cmd;
	t_pvec		*args_vec;
	t_pvec		*redirs_vec;

	cmd = (t_command *)malloc(sizeof(t_command));
	redirs_vec = pvec_new(16);
	args_vec = pvec_new(16);
	while (is_command_token(**tokens))
	{
		skip_spaces(tokens);
		if (!is_command_token(**tokens))
			break ;
		if (!parse_step(tokens, args_vec, redirs_vec))
			return (panic_free(cmd, args_vec, redirs_vec), NULL);
	}
	pvec_append(args_vec, NULL);
	cmd->argv = (char **)args_vec->arr;
	cmd->argc = args_vec->len - 1;
	free(args_vec);
	pvec_append(redirs_vec, NULL);
	cmd->redirs = (t_redir **)redirs_vec->arr;
	free(redirs_vec);
	return (cmd);
}
