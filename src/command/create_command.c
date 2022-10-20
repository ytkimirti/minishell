/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:03 by emakas            #+#    #+#             */
/*   Updated: 2022/10/20 18:20:45 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token_helper.h"
#include <stdio.h>
#include "../utils/utils.h"
#include "../../libft/libft.h" // Clion görmedi onu şaaparız

static t_command	*create_system_command(t_token **tokens);
static t_command	*create_builtin_command(int id, t_token **tokens);
static int			is_built_in(t_token *token);
static int			in_path(t_token *token);

t_command	*create_command(t_token **tokens)
{
	t_token *command_token;
	int		built_in_id;

	command_token = get_first_word(tokens); // tokenlerden ilk şeyi döndürecek. Ama ne tam ben de bilmiyorum
	built_in_id = is_built_in(command_token);
	if (built_in_id >= 0)
		return (create_builtin_command(built_in_id,tokens));
	else if (in_path(command_token))
		return (create_system_command(tokens));
	else
		printf("Command %s not found\n", dup_token_str(command_token));

}

static t_command	*create_system_command(t_token **tokens)
{}

static t_command	*create_builtin_command(int id, t_token **tokens)
{}

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