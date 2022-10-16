/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:26:45 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 14:33:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "unistd.h"

void	destroy_map(t_map *map)
{
	if (map != 0)
	{
		if (map->data != 0)
			free(map->data);
		free(map);
	}
}