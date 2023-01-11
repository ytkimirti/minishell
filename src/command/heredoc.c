/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:22:13 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 19:39:42 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include "readline/readline.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "signal.h"

static char	*readline_or_getnextline(const char *prompt)
{
	if (isatty(0))
		return (readline(prompt));
	return (get_next_line(0));
}

bool	*get_canceled_flag(void)
{
	static bool	is_canceled = false;

	return (&is_canceled);
}

static void	heredoc_handler(int sig)
{
	bool	*flag;

	(void)sig;
	flag = get_canceled_flag();
	*flag = true;
	close(0);
}

static void	heredoc_loop(const char *file, int fd)
{
	char	*line;

	while (true)
	{
		line = readline_or_getnextline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, file, ft_strlen(file) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
}

int	open_heredoc_file(const char *file)
{
	int		fds[2];
	void	(*mem_handler)(int);
	int		readline_dup;

	readline_dup = dup(0);
	if (pipe(fds) == -1)
		return (-1);
	get_canceled_flag();
	mem_handler = signal(SIGINT, heredoc_handler);
	heredoc_loop(file, fds[1]);
	signal(SIGINT, mem_handler);
	dup2(readline_dup, 0);
	close(readline_dup);
	close(fds[1]);
	if (*get_canceled_flag() == true)
	{
		close(fds[0]);
		*get_canceled_flag() = true;
		return (-1);
	}
	return (fds[0]);
}
