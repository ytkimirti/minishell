/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 12:40:36 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "token.h"
#include "executer.h"
#include "utils.h"
#include <assert.h>
#include "parser_utils.h"

char	*get_executable_path(const char *name)
{
	(void)name;
	return (ft_strdup("/bin/ls"));
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
int	calculate_length(t_token **tokens)
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

t_cmd	*create_cmd(t_token **tokens)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->stdin = 0;
	cmd->stdout = 1;
	cmd->stderr = 1;
	expand_all_args(cmd, tokens);
	cmd->path = NULL;
	if (cmd->argc > 0)
		cmd->path = get_executable_path(cmd->argv[0]);
	return (cmd);
}
