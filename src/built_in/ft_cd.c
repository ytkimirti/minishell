/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 09:24:14 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	ft_cd(t_command *command, t_stdio std)
{
	const char	*path;

	(void)std;
	if (command->argc > 1)
		path = command->argv[1];
	else
	{
		path = get_env("HOME", 4);
		if (path[0] == '\0')
			return (
				ft_putendl_fd("env variable 'HOME' is not set", std.err), 1);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd(strerror(errno), std.err);
		ft_putstr_fd("\n", std.err);
		return (1);
	}
	return (0);
}
