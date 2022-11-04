/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:19:09 by emakas            #+#    #+#             */
/*   Updated: 2022/10/31 14:38:15 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h" 
#include <stdlib.h>

static void	free_args(t_command *command)
{
	int	i;

	i = 0;
	while (command->argv[i] != NULL)
	{
		free(command->argv[i]);
		i++;
	}
	free(command->argv);
}

static void	free_redirection(t_command *command)
{
	if (command->redir_file == NULL)
		return ;
	free(command->redir_file);
}

void	free_command(t_command *command)
{
	free_args(command);
	free_redirection(command);
	free(command);
}
