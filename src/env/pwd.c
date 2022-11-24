/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:53:13 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 13:53:30 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <stdio.h>
#include "env.h"
#include <unistd.h>

void	update_pwd_variable(void)
{
	char	buf[MAXPATHLEN];

	if (getcwd(buf, MAXPATHLEN) == NULL)
	{
		perror("getcwd error");
		return ;
	}
	set_env("PWD", buf);
}
