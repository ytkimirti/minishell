/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:02 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

static int	calculate_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

static void	print_single_env(char *env, int fd)
{
	int	index;
	int	eq_occured;

	index = 0;
	eq_occured = 0;
	while (env[index] != '\0')
	{
		if (env[index] == '=' && eq_occured++ == 0)
			ft_putstr_fd("=\"", fd);
		else
			ft_putchar_fd(env[index], fd);
		index++;
	}
	ft_putendl_fd("\"", fd);
}

static void	print_all_exports(t_stdio std)
{
	char	**env;
	int		i;

	env = extract_env();
	sort((void **)env, calculate_env_len(env), (t_compare_func)ft_strcmp);
	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd("export ", std.out);
		print_single_env(env[i], std.out);
		i++;
	}
	free(env);
}

// "asd=" ok
// "asd"  ok
// "=asd" err
// "="    err
// ""     err
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
		if (i == 0)
			return (ft_putendl_fd("Syntax error", std.err), 1);
		if (str[i] == '\0')
			set_env(str, get_env(str, i));
		else
		{
			str[i] = '\0';
			set_env(str, str + i + 1);
		}
		index++;
	}
	return (0);
}
