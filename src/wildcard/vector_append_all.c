/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_append_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:54:32 by emakas            #+#    #+#             */
/*   Updated: 2022/12/28 13:20:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include <stdlib.h>

/**
 * 
 * @param vector_dest vector to be a
 */
void	vector_append_all(t_pvec *vector_dest, t_pvec *vector_src)
{
	int	index;

	index = 0;
	while (index < vector_src->len)
	{
		pvec_append(vector_dest, vector_src->arr[index]);
		index++;
	}
}
