/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:12:09 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 17:25:37 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "built_in.h"
#include "libft.h"
#include "env.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	ft_exit(t_command *command, t_stdio std)
{
	int	status;

	(void)std;
	status = 0;
	if (command->argc == 2)
		status = ft_atoi(command->argv[1]);
	exit(status);
}
