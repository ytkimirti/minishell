/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:23:18 by emakas            #+#    #+#             */
/*   Updated: 2022/10/20 18:47:47 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <unistd.h>

int	(*get_builtin(int id))(t_command *command, char **args)
{
	int	(**function_list)(t_command *, char **);

	function_list = get_function_list();
	return (function_list[id]);
}

int	(**get_function_list(void))(t_command *command, char **args)
{
	static int	(**list)(t_command *, char **) = {ft_cd,
		ft_echo,
		ft_env,
		ft_exit,
		ft_export,
		ft_pwd,
		ft_unset};

	return (list);
}

char	*get_builtin_command_list(void)
{
	static char	**list = {"cd",
		"echo",
		"env",
		"exit",
		"export",
		"pwd",
		"unset"};

	return (list);
}
