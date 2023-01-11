/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:45:27 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 19:22:44 by ykimirti         ###   ########.tr       */
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
#include "command_utils.h"

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
