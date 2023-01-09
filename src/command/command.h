/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
/*   Updated: 2023/01/09 16:40:41 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H

# define COMMAND_H

# include "token.h"
# include "stdbool.h"
# include "tstdio.h"

/*
 * For now it's like this. Since it has
 * REDIR_IN
 * REDIR_OUT stuff...
 */
typedef struct s_redir {
	char			*str;
	t_token_type	type;
}	t_redir;

/**
 * @brief Holds minimum data required for a command
 * to be executed in shell. The command path is found
 * from argv[0]
 *
 * Holds redirections as a null terminated array
 * 	REDIR_IN dummyfile
 * 	REDIR_IN inputfile
 * 	REDIR_OUT outfile
 * 	...
 */
typedef struct s_command {
	char			**argv;
	int				argc;
	t_redir			**redirs;
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
