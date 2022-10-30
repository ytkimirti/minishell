/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:03 by emakas            #+#    #+#             */
/*   Updated: 2022/10/28 18:15:47 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token_helper.h"
#include <stdio.h>
#include "../built_in/built_in.h"
#include "../utils/utils.h"
#include "../../libft/libft.h" // Clion görmedi onu şaaparız

#if 0

t_command	*create_command(t_token **tokens)
{
	t_token		*command_token;
	t_cmdtype	cmd_type;

	command_token = get_first_word(tokens);
	cmd_type = get_ebin(command_token);
	if (cmd_type != EXEC)
		return (create_builtin_command(cmd_type, tokens));
	else if (in_path(command_token))
		return (create_system_command(tokens));
	else
		printf("Command %s not found\n", dup_token_str(command_token));
}

static t_command	*create_system_command(t_token **tokens)
{
}

static t_command	*create_builtin_command(t_cmdtype bin, t_token **tokens)
{
	t_command	*command;

	if (tokens[0] == NULL)
		return (NULL);
	command = malloc(sizeof(t_command));
	command->command_path = dup_token_str(tokens[0]);
	command->argc = read_args(tokens, &(command->argv));
	command->execute = get_bfun(bin);
	return (command);
}

#endif

///**
// * @brief Looks in path for given command.
// * 
// * @return int 1 if it is in path, else zero
// */
//static int	in_path()
//{
//	return (0);
//}
