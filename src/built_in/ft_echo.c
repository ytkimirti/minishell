/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:59:44 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 07:04:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "libft.h"

int	ft_echo(t_command *cmd)
{
	int	i;

	i = 1;
	while (i < cmd->argc)
	{
		write(0, cmd->argv[i], ft_strlen(cmd->argv[i]));
		i++;
	}
	write(0, "\n", 1);
	return (0);
}
