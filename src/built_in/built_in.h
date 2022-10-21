/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/10/21 15:40:17 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../command/command.h"

enum e_built_ins {
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	NONE
};

int			(*get_bfun(e_built_ins built_in))(t_command *, char **);
e_built_ins	get_ebin(t_token *token);

int			ft_cd(t_command *command, char **args);
int			ft_echo(t_command *command, char **args);
int			ft_env(t_command *command, char **args);
int			ft_exit(t_command *command, char **args);
int			ft_export(t_command *command, char **args);
int			ft_pwd(t_command *command, char **args);
int			ft_unset(t_command *command, char **args);


#endif;