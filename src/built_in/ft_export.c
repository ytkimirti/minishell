/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 09:10:04 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

static void	print_all_exports(t_stdio std)
{
	char	**env;
	int		i;

	env = extract_env();
	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd("export ", std.out);
		ft_putendl_fd(env[i], std.out);
		i++;
	}
	free(env);
}

int	ft_export(t_command *command, t_stdio std)
{
	int		index;
	int		i;
	char	*str;

	if (command->argc < 2)
		return (print_all_exports(std), 0);
	index = 1;
	while (command->argv[index] != NULL)
	{
		str = command->argv[index];
		i = 0;
		while (str[i] != '\0' && str[i] != '=')
			i++;
		if (str[i] == '\0')
			return (ft_putendl_fd("No '=' found in string", std.err), 1);
		if (i == 0)
			return (ft_putendl_fd("No key found before '='", std.err), 1);
		str[i] = '\0';
		set_env(str, str + i + 1);
		index++;
	}
	return (0);
}
