/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 17:20:40 by ykimirti         ###   ########.tr       */
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
	path = command->argv[1];
	if (path == NULL)
		path = get_env("HOME", 4);
	if (chdir(path) == -1)
	{
		ft_putstr_fd(strerror(errno), std.err);
		ft_putstr_fd("\n", std.err);
		return (1);
	}
	return (0);
}
