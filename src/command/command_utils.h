/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:29:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/26 19:31:06 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_UTILS_H

# define COMMAND_UTILS_H

# include "command.h"

/*
 * Finds a builtin with the command->argv[0],
 * opens the fds using open_output_file and open_input_file,
 * executes that function
 * closes those fds, no dup2 or fork is used.
 *
 * Returns -1 if it does not find any builtins with that name
 * Returns SHELL_ERROR if something happens with opening a file
 */
int			execute_builtin(t_command *command, t_stdio std);

int			open_output_file(const char *file, bool is_append);

int			open_input_file(const char	*file, bool is_heredoc);

#endif
