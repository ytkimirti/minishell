/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/10/20 18:43:07 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../command/command.h"

int		(*get_builtin(int id))(t_command *, char **);
int		(**get_function_list(void))(t_command *command, char **args);
char	*get_builtin_command_list();

int		ft_cd(t_command *command, char **args);
int		ft_echo(t_command *command, char **args);
int		ft_env(t_command *command, char **args);
int		ft_exit(t_command *command, char **args);
int		ft_export(t_command *command, char **args);
int		ft_pwd(t_command *command, char **args);
int		ft_unset(t_command *command, char **args);


#endif;