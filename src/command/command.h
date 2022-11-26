/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
/*   Updated: 2022/11/26 10:50:48 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H

# define COMMAND_H

# include "token.h"
# include "stdbool.h"
# include "tstdio.h"

/**
 * @brief Holds minimum data required for a command
 * to be executed in shell. The command path is found
 * from argv[0]
 */
typedef struct s_command {
	char			**argv;
	int				argc;
	char			*out_file;
	char			*in_file;
	bool			is_append;
	bool			is_heredoc;
}	t_command;

void		free_command(t_command *command);

/**
 * @brief Main command execution command. This checks against
 * builtin functions. If not found, finds binary from PATH
 *
 * @return int return code. On error, prints it to stderr and
 * returns SHELL_ERROR
 */
int			execute_command(t_command *command, t_stdio std, bool is_async);

#endif
