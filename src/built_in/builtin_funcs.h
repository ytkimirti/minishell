/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_funcs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/11/24 12:45:36 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCS_H

# define BUILTIN_FUNCS_H

# include "command.h"

int			ft_cd(t_command *command, t_stdio std);
int			ft_echo(t_command *command, t_stdio std);
int			ft_env(t_command *command, t_stdio std);
int			ft_exit(t_command *command, t_stdio std);
int			ft_export(t_command *command, t_stdio std);
int			ft_pwd(t_command *command, t_stdio std);
int			ft_unset(t_command *command, t_stdio std);
int			ft_path(t_command *command, t_stdio std);

#endif
