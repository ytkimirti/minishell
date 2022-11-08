/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:07:22 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "error.h"
#include <stdlib.h>
#include "libft.h"

bool	*error_false(const char *msg)
{
	error(msg);
	return (false);
}

void	*error_null(const char *msg)
{
	error(msg);
	return (NULL);
}

void	error(const char *msg)
{
	ft_printf("%s\n", msg);
}

void	*malloc_error(void)
{
	perror("Malloc failed");
	exit(1);
	return (NULL);
}
