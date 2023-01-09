/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:19:09 by emakas            #+#    #+#             */
/*   Updated: 2023/01/09 17:54:49 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h" 
#include <stdlib.h>

static void	free_redirs(t_command *command)
{
	int	i;

	i = 0;
	while (command->redirs[i] != NULL)
	{
		free(command->redirs[i]->str);
		free(command->redirs[i]);
		i++;
	}
	free(command->redirs);
}

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

void	free_command(t_command *command)
{
	free_args(command);
	free_redirs(command);
	free(command);
}
