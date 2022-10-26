/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 17:59:42 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "token.h"

typedef int		(*t_cmdfunc)(struct s_command *);

typedef enum e_redir_type
{
	APPEND,
	OUT,
	IN
}	t_redir_type;

struct s_command {
	char			**argv;
	int				argc;
	t_redir_type	redir_type;
	char			*redir_file;
};

/**
 * @brief Represents commands in shell
 * Every command has some fields like:
 * - Executable file address
 * - Argument lists
 * - Environment Variables
 */
typedef struct s_command	t_command;

/**
 * @brief Create a command object
 * 
 * @param tokens 
 * @return t_command* 
 */
t_command	*create_command(t_token **tokens);
void		destroy_command(t_command *command);

/**
 * @brief Default execution method for commands
 * Built in commands and external commands runs differently
 * 
 * @param self Command pointer for accessing type fields
 * @param envp environment list
 * @return int return code. -1 if execution failed.
 */
int			execute_command(t_command *self);

#endif
