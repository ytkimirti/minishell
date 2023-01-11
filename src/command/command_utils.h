/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:29:43 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 19:22:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_UTILS_H

# define COMMAND_UTILS_H

# include "command.h"
# include "built_in.h"

/*
 * Opens all the redirection files
 * Executes the builtin with the given function
 * Closes all the redirection files
 * Returns status
 */
int		execute_builtin(t_command *command, t_stdio std, t_builtin_func func);

bool	open_redir_files(t_redir **redirs, t_ivec *opened_fds, t_stdio *std);

int		open_output_file(const char *file, bool is_append);

int		open_input_file(const char	*file, bool is_heredoc);

int		open_heredoc_file(const char *file);

#endif
