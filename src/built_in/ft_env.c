/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 08:31:42 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	ft_env(t_command *command, t_stdio std)
{
	char	**env_str;
	int		i;

	(void)command;
	env_str = extract_env();
	if (env_str == NULL)
		return (1);
	i = 0;
	while (env_str[i] != NULL)
	{
		ft_putendl_fd(env_str[i], std.out);
		i++;
	}
	free(env_str);
	return (0);
}
