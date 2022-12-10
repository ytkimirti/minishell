/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_pvec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:51:32 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/10 17:51:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	append_to_pvec(char **arr, t_pvec *vec)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		pvec_append(vec, arr[i]);
		i++;
	}
}
