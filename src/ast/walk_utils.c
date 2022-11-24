/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:47:15 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 12:20:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_utils.h"
#include <stdio.h>
#include <unistd.h>

bool	close_unwanted(t_ivec *fds)
{
	while (fds->len > 0)
	{
		if (close(fds->arr[fds->len - 1]) == -1)
		{
			perror("pipe close error");
			return (false);
		}
		fds->len -= 1;
	}
	return (true);
}
