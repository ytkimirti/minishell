/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/10/28 18:12:16 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H

# define BUILT_IN_H

# include "command.h"
# include "ast.h"

int			ft_cd(t_command *command, t_stdio std);
int			ft_echo(t_command *command, t_stdio std);
int			ft_env(t_command *command, t_stdio std);
int			ft_exit(t_command *command, t_stdio std);
int			ft_export(t_command *command, t_stdio std);
int			ft_pwd(t_command *command, t_stdio std);
int			ft_unset(t_command *command, t_stdio std);

#endif
