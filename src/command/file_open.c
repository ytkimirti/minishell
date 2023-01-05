/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:45:27 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/02 17:40:26 by ykimirti         ###   ########.tr       */
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

int	open_output_file(const char *file, bool is_append)
{
	int	fd;
	int	append_mask;

	if (is_append)
		append_mask = O_APPEND;
	else
		append_mask = O_TRUNC;
	fd = open(file, O_CREAT | O_WRONLY | append_mask,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ((perror("open output file error"), -1));
	return (fd);
}

static void	heredoc_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	close(0);
}

static int	open_heredoc_file(const char *file)
{
	char	*line;
	int		fds[2];
	void	(*mem_handler)(int);
	int		readline_dup;

	readline_dup = dup(0);
	if (pipe(fds) == -1)
		return (-1);
	mem_handler = signal(SIGINT, heredoc_handler);
	while (true)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, file, ft_strlen(file) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fds[1]);
		free(line);
	}
	signal(SIGINT, mem_handler);
	return (dup2(readline_dup, 0), close(readline_dup), close(fds[1]), fds[0]);
}

int	open_input_file(const char	*file, bool is_heredoc)
{
	int	fd;

	if (is_heredoc)
		return (open_heredoc_file(file));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open input file error"), -1);
	return (fd);
}
