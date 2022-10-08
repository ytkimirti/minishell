/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:18:17 by emakas            #+#    #+#             */
/*   Updated: 2022/10/06 14:57:34 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "../token.h"

struct s_stdio{
	int	in_new;
	int	out_new;
	int	err_new;
};

struct s_command {
	char	*command_path;
	char	**argv;
	int		argc;
	int (*execute)(struct s_command *, char **);
};

/**
 * @brief Represents commands in shell
 * Every command has some fields like:
 * - Executable file address
 * - Argument lists
 * - Environment Variables
 */
typedef struct s_command t_command;

/**
 * @brief Create a command object
 * 
 * @param tokens 
 * @return t_command* 
 */
t_command	*create_command(t_token *tokens);
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


/**
 * @brief Executes command in new process
 * 
 * @param newio 
 * @param command 
 * @return int return code of executed command
 */
int			execute_forked(struct s_stdio newio, t_command *command);

#endif