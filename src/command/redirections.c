/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:04:27 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/09 17:56:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "command_utils.h"
#include "libft.h"
#include "ast.h"
#include "tstdio.h"
#include <stdio.h>

static int	open_redir_file(t_redir *redir, t_stdio *std)
{
	int	fd;

	if (redir->type == REDIR_APPEND || redir->type == REDIR_OUT)
	{
		fd = open_output_file(redir->str, redir->type == REDIR_APPEND);
		if (fd == -1)
			return (-1);
		std->out = fd;
	}
	else if (redir->type == REDIR_IN || redir->type == REDIR_HEREDOC)
	{
		fd = open_input_file(redir->str, redir->type == REDIR_HEREDOC);
		if (fd == -1)
			return (-1);
		std->in = fd;
	}
	else
		fd = SHELL_ERROR;
	return (fd);
}

bool	open_redir_files(t_redir **redirs, t_ivec *opened_fds
		, t_stdio *std)
{
	int	fd;

	while (*redirs != NULL)
	{
		fd = open_redir_file(*redirs, std);
		if (fd == -1)
			return (false);
		if (opened_fds != NULL)
		{
			ivec_append(opened_fds, fd);
		}
		redirs++;
	}
	return (true);
}
