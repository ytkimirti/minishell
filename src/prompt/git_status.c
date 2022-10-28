/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:51:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:08:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "colors.h"
#include "libft.h"
#include "git_status_utils.h"
#include "stdio.h"
#include <stdbool.h>

#define NO_GIT

#ifndef GIT_PATH

# define GIT_PATH "/us r/bin/git"

#endif

#ifndef NO_GIT

/*
 * Returns whether it failed before or not
 */
static bool	get_did_git_fail_last_time(bool did_fail)
{
	static bool	s_did_fail = false;

	if (did_fail == true)
		s_did_fail = did_fail;
	return (s_did_fail);
}

static void	handle_child(int gitpipe[2])
{
	int	dev_null;

	close(gitpipe[0]);
	dup2(gitpipe[1], 1);
	close(gitpipe[1]);
	dev_null = open("/dev/null", O_WRONLY);
	dup2(dev_null, 2);
	close(dev_null);
	execve(GIT_PATH,
		(char *[]){"git", "symbolic-ref", "--quiet", "HEAD", NULL},
		NULL);
	exit(127);
}

static void	handle_git_fail(int status)
{
	int	status_code;

	status_code = WEXITSTATUS(status);
	if (get_did_git_fail_last_time(false))
		return ;
	if (status_code == 127)
	{
		get_did_git_fail_last_time(true);
		ft_printf(BYEL "WARN:" RST " git is not found in variable "
			"GIT_PATH which is %s\n", GIT_PATH);
	}
}

// Uses command 
// git symbolic-ref --quiet HEAD 2>/dev/null
char	*get_git_branch(void)
{
	int			gitpipe[2];
	pid_t		pid;
	int			status;
	char		*res;

	if (get_did_git_fail_last_time(false))
		return (NULL);
	if (pipe(gitpipe) == -1)
		return (NULL);
	pid = fork();
	if (pid == 0)
		handle_child(gitpipe);
	close(gitpipe[1]);
	res = handle_git_output(gitpipe[0]);
	waitpid(pid, &status, 0);
	if (status != 0)
		handle_git_fail(status);
	close(gitpipe[0]);
	return (res);
}

#endif

#ifdef NO_GIT

char	*get_git_branch(void)
{
	return (NULL);
}

#endif
