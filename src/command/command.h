/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/21 15:53:29 by emakas           ###   ########.fr       */
=======
/*   Updated: 2022/10/25 14:10:11 by ykimirti         ###   ########.tr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
<<<<<<< HEAD
# include "../tokenizer/token.h"

/**
 * @brief Built in commands
 * 
 */
=======
# include "token.h"
>>>>>>> main


struct s_command {
	char	*command_path;
	char	**argv;
	int		argc;
	int		(*execute)(struct s_command *, char **);
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
int			execute_default(t_command *self, char **envp);

<<<<<<< HEAD
#endif
=======
/**
 * @brief Executes command in new process
 * 
 * @param newio 
 * @param command 
 * @return int return code of executed command
 */
int			execute_forked(struct s_stdio newio, t_command *command);

#endif
>>>>>>> main
