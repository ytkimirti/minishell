/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 21:11:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "ast_utils.h"
#include "built_in.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/wait.h>

/*
 * This is only for processes that are forked
 */
static void	dup_fds(t_command *command, t_stdio std)
{
	int	fd;

	if (command->out_file != NULL)
	{
		fd = open_output_file(command->out_file, command->is_append);
		if (fd == -1)
			exit(SHELL_ERROR);
		ft_dup2(fd, 1);
		close(fd);
	}
	else
		ft_dup2(std.out, 1);
	if (command->in_file != NULL)
	{
		fd = open_input_file(command->in_file);
		if (fd == -1)
			exit(SHELL_ERROR);
		ft_dup2(fd, 0);
		close(fd);
	}
	else
		ft_dup2(std.in, 0);
	ft_dup2(std.err, 2);
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
	dup_fds(command, std);
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

int	execute_command(t_command *command, t_stdio std, bool is_sync)
{
	pid_t	pid;
	int		status;
	int		builtin_status;

	if (command->argv[0] == NULL)
		return (1);
	if (ft_strncmp(command->argv[0], "echo", sizeof("echo")) == 0)
		return (ft_echo(command, std));
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), SHELL_ERROR);
	if (pid == 0)
		exec_child(command, std);
	close_std(std);
	if (!is_async)
	{
		dprintf(2, "Waiting for command %s\n", command->argv[1]);
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
