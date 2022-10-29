/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:59:44 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 18:11:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"

int	ft_echo(t_command *command, t_stdio std)
{
	char	**str;

	str = command->argv + 1;
	while (*str != NULL)
	{
		ft_putstr_fd(*str, std.out);
		str++;
	}
	return (0);
}
