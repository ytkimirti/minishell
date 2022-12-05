/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_append_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:54:32 by emakas            #+#    #+#             */
/*   Updated: 2022/12/05 13:26:12 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include <stdlib.h>

void	vector_append_all(t_pvec *vector_dest, t_pvec *vector_src)
{
	int	index;

	index = 0;
	while (vector_src->arr[index] != NULL)
	{
		pvec_append(vector_dest, vector_src->arr[index]);
		index++;
	}
}
