/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:03 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 12:43:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token_helper.h"
#include <stdio.h>
#include "../built_in/built_in.h"
#include "../utils/utils.h"
#include "../../libft/libft.h" // Clion görmedi onu şaaparız

static t_command	*create_system_command(t_token **tokens);
static t_command	*create_builtin_command(int id, t_token **tokens);
static int			is_built_in(t_token *token);
static int			in_path(t_token *token);

t_command	*create_command(t_token **tokens)
{
	t_token *command_token;
	e_builtins	b_command;

	command_token = get_first_word(tokens);
	b_command = get_ebin();
	if (b_command != NONE)
		return (create_builtin_command(built_in_id,tokens));
	else if (in_path(command_token))
		return (create_system_command(tokens));
	else
		printf("Command %s not found\n", dup_token_str(command_token));

}

static t_command	*create_system_command(t_token **tokens)
{}

static t_command	*create_builtin_command(int id, t_token **tokens)
{
	t_command	*command;
	
	command = malloc(sizeof(t_command));
	command->
}

static int	is_built_in(t_token *token)
{
	char	**built_ins;
	int		index;

	if (built_ins == NULL)
		built_ins = {"echo","cd","pwd","export","unset","env","exit",NULL};
	while(built_ins[index] != NULL)
	{
		if (ft_strncmp(built_ins[index], token->str, token->len))
			return (index);
		index++;
	}
	return (-1);
}