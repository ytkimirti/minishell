/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/13 14:46:19 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/wait.h>
#include "command_utils.h"
#include <stdio.h>
#include "env.h"

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
	const char	*path;
	char		**envp;
	
	path = find_executable(command->argv[0]);
	dprintf(2, "%s\n", path);
	if (path == NULL)
		exit(42);
	envp = extract_env();
	dup2(std.in, 0);
	dup2(std.out, 1);
	dup2(std.err, 2);
	close_std(std);
	execve(path, command->argv, envp);
	perror("Execve error");
	exit(127);
}

int	execute_command(t_command *command, t_stdio std, bool is_sync)
{
	pid_t	pid;
	int		status;

	dprintf(2, "Executing with %d -> %d\n", std.in, std.out);
	if (command->argv[0] == NULL)
		return (1);
	if (ft_strncmp(command->argv[0], "echo", sizeof("echo")) == 0)
		return (ft_echo(command, std));
	if (ft_strncmp(command->argv[0], "path", sizeof("path")) == 0)
		return (ft_path(command, std));
	pid = fork();
	if (pid == 0)
		exec_child(command, std);
	close_std(std);
	if (is_sync)
	{
		dprintf(2, "Waiting for command %s\n", command->argv[1]);
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
