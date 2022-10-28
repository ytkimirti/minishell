/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:19:09 by emakas            #+#    #+#             */
/*   Updated: 2022/10/28 08:15:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h" 

static void	free_args(t_command *command)
{
	free_content(command->argv);
	free(command->argv);
}

static void	free_command_name(t_command *command)
{
	free(command->command_path);
}

void	destroy_command(t_command *command)
{
	free_args(command);
	free_command_path(command);
	free(command);
}
