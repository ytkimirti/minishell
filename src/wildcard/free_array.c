/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:24:23 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/22 15:24:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(char **array)
{
	char	**p;

	p = array;
	while (*p != NULL)
	{
		free(*p);
		p++;
	}
	free(array);
}
