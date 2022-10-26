/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 15:45:14 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../command/command.h"

typedef enum e_cmdtype {
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	EXEC
}	t_cmdtype;

t_cmdfunc	get_bfun(t_cmdtype built_in);
t_cmdtype	get_ebin(t_token *token);

int			ft_cd(t_command *command);
int			ft_echo(t_command *command);
int			ft_env(t_command *command);
int			ft_exit(t_command *command);
int			ft_export(t_command *command);
int			ft_pwd(t_command *command);
int			ft_unset(t_command *command);

#endif