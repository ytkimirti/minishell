/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:47:00 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 13:08:55 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "command_utils.h"
#include "stdio.h"
#include <unistd.h>

static bool	out_file_thing(t_command *command, t_stdio *std, int *ofile)
{
	if (command->out_file == NULL)
	{
		*ofile = -1;
		return (true);
	}
	*ofile = open_output_file(command->out_file, command->is_append);
	if (*ofile == -1)
		return (false);
	std->out = *ofile;
	return (true);
}

static int	in_file_thing(t_command *command, t_stdio *std, int *ifile)
{
	if (command->in_file == NULL)
	{
		*ifile = -1;
		return (true);
	}
	*ifile = open_input_file(command->in_file);
	if (*ifile == -1)
		return (false);
	std->in = *ifile;
	return (true);
}

int	execute_builtin(t_command *command, t_stdio std)
{
	t_builtin_func	func;
	int				outfile;
	int				infile;
	int				ret;

	func = find_builtin_function(command->argv[0]);
	if (func == NULL)
		return (-1);
	if (!in_file_thing(command, &std, &infile))
		return (SHELL_ERROR);
	if (!out_file_thing(command, &std, &outfile))
		return (SHELL_ERROR);
	ret = func(command, std);
	if (outfile != -1)
		close(outfile);
	if (infile != -1)
		close(infile);
	return (ret);
}
