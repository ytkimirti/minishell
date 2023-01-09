/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:47:00 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/09 17:40:09 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "command_utils.h"
#include "stdio.h"
#include "vector.h"
#include <unistd.h>

void	close_fds(t_ivec *opened_fds)
{
	int	i;

	i = 0;
	while (i < opened_fds->len)
	{
		close(opened_fds->arr[i]);
		i++;
	}
}

// Only execute the func if there are no errors while executing open_redir_files
int	execute_builtin(t_command *command, t_stdio std, t_builtin_func func)
{
	int				ret;
	t_ivec			*opened_fds;

	opened_fds = ivec_new(4);
	if (!open_redir_files(command->redirs, opened_fds, &std))
	{
		close_fds(opened_fds);
		ivec_del(opened_fds);
		return (SHELL_ERROR);
	}
	ret = func(command, std);
	close_fds(opened_fds);
	ivec_del(opened_fds);
	return (ret);
}
