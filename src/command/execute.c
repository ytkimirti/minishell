/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 17:33:20 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "ast_utils.h"
#include "built_in.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/wait.h>
#include "command_utils.h"
#include <stdio.h>
#include "env.h"
#include <error.h>
#include <errno.h>

static void	ft_dup2(int src, int target)
{
	if (src == target)
		return ;
	if (dup2(src, target) == -1)
		exit((perror("dup2 error"), SHELL_ERROR));
}

static void	exec_child(t_command *command, t_stdio std)
{
	const char	*path;
	char		**envp;

	path = find_executable(command->argv[0]);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: Unknown command: ", 2);
		ft_putstr_fd(command->argv[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	envp = extract_env();
	ft_dup2(std.in, 0);
	ft_dup2(std.out, 1);
	ft_dup2(std.err, 2);
	if (!close_unwanted(std.unwanted_fds))
		exit(SHELL_ERROR);
	execve(path, command->argv, envp);
	perror("execve error");
	if (errno == ENOEXEC)
		exit(128);
	if (errno == ENOENT)
		exit (127);
	exit(126);
}

static int	execute_builtin(t_command *command, t_stdio std)
{
	if (ft_strncmp(command->argv[0], "echo", sizeof("echo")) == 0)
		return (ft_echo(command, std));
	if (ft_strncmp(command->argv[0], "path", sizeof("path")) == 0)
		return (ft_path(command, std));
	if (ft_strncmp(command->argv[0], "cd", sizeof("cd")) == 0)
		return (ft_cd(command, std));
	if (ft_strncmp(command->argv[0], "pwd", sizeof("pwd")) == 0)
		return (ft_pwd(command, std));
	if (ft_strncmp(command->argv[0], "exit", sizeof("exit")) == 0)
		return (ft_exit(command, std));
	return (-1);
}

int	execute_command(t_command *command, t_stdio std, bool is_sync)
{
	pid_t	pid;
	int		status;
	int		builtin_status;

	if (command == NULL || command->argv[0] == NULL)
		return (SHELL_ERROR);
	builtin_status = execute_builtin(command, std);
	if (builtin_status != -1)
		return (builtin_status);
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), SHELL_ERROR);
	if (pid == 0)
		exec_child(command, std);
	if (is_sync)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
