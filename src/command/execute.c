/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:12 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 20:41:06 by ykimirti         ###   ########.tr       */
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
#include "vector.h"
#include <error.h>
#include <errno.h>
#include <fcntl.h>

static void	exit_based_on_execve_err(void)
{
	if (errno == ENOEXEC)
		exit(128);
	if (errno == ENOENT)
		exit (127);
	exit(126);
}

// This is ACTUALLY forked. Finally...
static void	exec_child(t_command *command, t_stdio std)
{
	const char	*path;
	char		**envp;

	if (!open_redir_files(command->redirs, NULL, &std))
		exit(SHELL_ERROR);
	if (command->argv[0] == NULL)
		exit(0);
	path = find_executable(command->argv[0]);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: Unknown command: ", 2);
		ft_putendl_fd(command->argv[0], 2);
		exit(127);
	}
	envp = extract_env();
	dup2(std.in, 0);
	dup2(std.out, 1);
	if (!close_unwanted(std.unwanted_fds))
		exit(SHELL_ERROR);
	signal(SIGQUIT, SIG_DFL);
	execve(path, command->argv, envp);
	exit_based_on_execve_err();
}

// If a builtin
// 		open all files
//		execute the code with the new std
//		close all files
//		return
// open all files
// actually redirect std to 0 and 1
// execute
// wait for sync and return
int	execute_command(t_command *command, t_stdio std, bool is_sync)
{
	pid_t			pid;
	int				status;
	t_builtin_func	func;

	if (command == NULL)
		return (SHELL_ERROR);
	if (command->argv[0] != NULL)
	{
		func = find_builtin_function(command->argv[0]);
		if (func != NULL)
			return (execute_builtin(command, std, func));
	}
	pid = fork();
	if (pid == -1)
		return (perror("fork error"), SHELL_ERROR);
	if (pid == 0)
		exec_child(command, std);
	if (is_sync)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
