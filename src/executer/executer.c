/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:03:45 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/06 11:48:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <unistd.h>

extern char	**environ;

void	execute_cmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->stdin != 0)
			dup2(cmd->stdin, 0);
		if (cmd->stdout != 0)
			dup2(cmd->stdout, 1);
		if (cmd->stderr != 0)
			dup2(cmd->stderr, 2);
		execve(cmd->path, cmd->argv, environ);
	}
}
