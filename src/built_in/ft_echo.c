/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:59:44 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/21 18:44:31 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"

int	ft_echo(t_command *command, t_stdio std)
{
	char	**str;
	bool	send_newline;

	if (command->argc == 0)
		return (ft_putendl_fd("", std.out), 0);
	str = command->argv + 1;
	send_newline = true;
	while (*str != NULL)
	{
		if (ft_strncmp(*str, "-n", 3) == 0)
		{
			send_newline = false;
			str++;
			continue ;
		}
		else
			ft_putstr_fd(*str, std.out);
		str++;
		if (*str != NULL)
			ft_putstr_fd(" ", std.out);
	}
	if (send_newline)
		write(std.out, "\n", 1);
	return (0);
}
