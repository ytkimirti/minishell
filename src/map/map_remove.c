/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:47:17 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 15:49:38 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"

void	map_remove(t_map *map, char *key)
{
	int	code;

	code = hashcode(key);
	if (map->size > code && map->data[code] != 0)
		map->data[code] = 0;
}
