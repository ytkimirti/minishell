/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/10/21 18:16:10 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../command/command.h"

enum e_builtins {
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	NONE
};

int			(*get_bfun(e_builtins built_in))(t_command *, char **);
e_builtins	get_ebin(t_token *token);

int			ft_cd(t_command *command, char **args);
int			ft_echo(t_command *command, char **args);
int			ft_env(t_command *command, char **args);
int			ft_exit(t_command *command, char **args);
int			ft_export(t_command *command, char **args);
int			ft_pwd(t_command *command, char **args);
int			ft_unset(t_command *command, char **args);


#endif;