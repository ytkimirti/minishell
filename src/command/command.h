/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
/*   Updated: 2022/10/30 22:59:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H

# define COMMAND_H

# include "token.h"
# include "stdbool.h"
# include "tstdio.h"

/**
 * @brief Types of redirections.
 * Append (>>)
 * OUT (>)
 * IN (<)
 * */
typedef enum e_redir_type
{
	APPEND,
	OUT,
	IN
}	t_redir_type;

/**
 * @brief Holds minimum data required for a command
 * to be executed in shell. The command path is found
 * from argv[0]
 */
typedef struct s_command {
	char			**argv;
	int				argc;
	t_redir_type	redir_type;
	char			*redir_file;
}	t_command;

/**
 * @brief Create a command object by parsing tokens until it
 * sees a control structure.
 * 
 * @param tokens 
 * @return t_command* 
 */
t_command	*create_command(t_token **tokens);
void		free_command(t_command *command);

/**
 * @brief Main command execution command. This checks against
 * builtin functions. If not found, finds binary from PATH
 *
 * @return int return code. -1 if execution failed.
 */
int			execute_command(t_command *command, t_stdio std, bool is_async);

#endif
