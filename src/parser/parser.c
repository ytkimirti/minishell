/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/23 21:35:02 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/vector.h"
#include "tokenizer.h"
#include "token.h"
#include "executer.h"
#include "utils.h"
#include <assert.h>

static char	*get_executable_path(const char *name)
{
	(void)name;
	return ft_strdup("/bin/ls");
}

void	free_cmd(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->argv[i] != NULL)
	{
		free(cmd->argv[i]);
		i++;
	}
	free(cmd->argv);
	if (cmd->path != NULL)
		free(cmd->path);
	free(cmd);
}

// Calculates the char length the token will take
// when it's expanded
static int	calculate_length(const t_token **tokens)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	assert(*tokens != NULL && tokens[0]->type != SPACE);
	while (tokens[i] != NULL && tokens[i]->type != SPACE)
	{
		if (tokens[i]->type == WORD)
		{
			len += tokens[i]->len;
		}
		i++;
	}
	return (len);
}

// If returns null, it means that it's the end of the command.
// For example when it sees a bracket or pipe token
static char	*expand_tokens(const t_token ***tokens_ref)
{
	const t_token	**tokens;
	int				i;
	char			*str;

	i = 0;
	tokens = *tokens_ref;
	assert(*tokens != NULL && tokens[0]->type != SPACE);
	while (tokens[i] != NULL && tokens[i]->type != SPACE)
		i++;
	str = malloc(sizeof(char) * calculate_length(tokens));
	free(str);
	*tokens_ref = tokens + i;
	return (ft_strdup("dummy"));
}

static void	expand_all_args(t_cmd *cmd, const t_token **tokens)
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

t_cmd	*create_cmd(const t_token **tokens)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->stdin = 0;
	cmd->stdout = 1;
	cmd->stderr = 1;
	expand_all_args(cmd, tokens);
	cmd->path = NULL;
	if (cmd->argc > 0)
		cmd->path = get_executable_path(cmd->argv[0]);
	return (cmd);
}
