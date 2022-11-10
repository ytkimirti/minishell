/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 15:45:09 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/wait.h>

static void	close_std(t_stdio std)
{
	if (std.in != 0)
		close(std.in);
	if (std.out != 1)
		close(std.out);
	if (std.err != 2)
		close(std.err);
}

static void	exec_child(t_command *command, t_stdio std)
{
	dup2(std.in, 0);
	dup2(std.out, 1);
	dup2(std.err, 2);
	close_std(std);
	execve(command->argv[0], command->argv, NULL);
	exit(127);
}

int	execute_command(t_command *command, t_stdio std, bool is_async)
{
	pid_t	pid;
	int		status;

	if (command->argv[0] == NULL)
		return (1);
	if (ft_strncmp(command->argv[0], "echo", sizeof("echo")) == 0)
		return (ft_echo(command, std));
	pid = fork();
	if (pid == 0)
		exec_child(command, std);
	close_std(std);
	if (!is_async)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
