/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:03 by emakas            #+#    #+#             */
/*   Updated: 2022/10/12 15:30:51 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token_adapter.h"
#include "libft.h"

static t_command	*create_system_command(t_token **tokens);
static t_command	*create_builtin_command(t_token **tokens);

t_command	*create_command(t_token **tokens)
{
	char	*command;

	command = get_fitst_word(tokens); // tokenlerden ilk şeyi döndürecek. Ama ne tam ben de bilmiyorum

	if (is_built_in(command))
	{
		/* init built in command */
		return (create_builtin_command(tokens));
	}
	else if (in_path(command))
	{
		/* init executable command */
		return (create_system_command(tokens));
	}
	else
	{
		/* Command %s not found. */
		printf("Command %s not found",command);
	}

}

static t_command	*create_system_command(t_token **tokens)
{}

static t_command	*create_builtin_command(t_token **tokens)
{}