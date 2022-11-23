/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 09:28:44 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	ft_pwd(t_command *command, t_stdio std)
{
	const char	*str;

	(void)command;
	str = get_env("PWD", 3);
	if (str[0] == '\0')
	{
		ft_putendl_fd("PWD environment variable is not set!", std.err);
		return (1);
	}
	ft_putendl_fd(str, std.out);
	return (0);
}
