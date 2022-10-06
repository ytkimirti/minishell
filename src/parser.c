/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:00:53 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/06 11:31:55 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/vector.h"
#include "tokenizer.h"
#include "token.h"
#include "executer.h"
#include "utils.h"

// Finds the executable with name in PATH. Name is not
// guaranteed to be a null terminated string so a length
// is passed by.
char	*get_executable_path(char *name, int len)
{
	(void)len;
	return (name);
}

// Converts an argument token to a string.
// Modifies the pointer to point to token after the
// argument token.
//    **Given pointer**      **Returned pointer**
// echo "Hello"   World     echo "Hello"   World
//      |                                |
//
// Here the returned pointer is to the space token.
char	*arg_token_to_str(t_token ***tokens)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	len = 0;
	i = 0;
	while (*tokens[i] != NULL && (*tokens)[i]->type != SPACE)
		len += (*tokens)[i++]->len;
	if (len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (tokens[i] != NULL && (*tokens)[i]->type != SPACE)
	{
		if ((*tokens)[i]->type == WORD)
		{
			ft_memcpy(str + j, (*tokens[i])->str, (*tokens)[i]->len);
			j += (*tokens[i])->len;
		}
		i++;
	}
	str[len + 1] = '\0';
	tokens += i;
	return (str);
}

// Trys to fill all of the args of cmd.
// Fills the first element of argv with the given
// heap allocated, null terminated name
void	fill_args(t_cmd *cmd, t_token **t, char *name)
{
	t_pvec	*argv;
	char	*str;

	argv = pvec_new(32);
	pvec_append(argv, name);
	while (*t != NULL)
	{
		str = arg_token_to_str(&t);
		if (str == NULL)
			break ;
		pvec_append(argv, str);
	}
	pvec_append(argv, NULL);
	cmd->argv = (char **)argv->arr;
	cmd->argc = argv->len - 1;
	free(argv);
}

t_cmd	create_cmd(t_token **tokens)
{
	t_cmd	cmd;
	int		i;
	t_token	*name_token;

	cmd.stdin = 0;
	cmd.stdout = 1;
	cmd.stderr = 0;
	cmd.path = NULL;
	i = 0;
	while (&tokens[i] != NULL && tokens[i]->type == SPACE)
		i++;
	if (&tokens[i] == NULL)
		return (cmd);
	if (tokens[i]->type != WORD)
	{
		ft_printf("Excepted command name. Aborting...");
		return (cmd);
	}
	name_token = tokens[i];
	cmd.path = get_executable_path(name_token->str, name_token->len);
	if (cmd.path == NULL)
	{
		ft_printf("Couldn't find executable in PATH");
		return (cmd);
	}
	fill_args(&cmd, tokens, dup_token_str(name_token));
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		free(cmd->argv[i]);
	}
	free(cmd->argv);
}
