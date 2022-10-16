/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:35:57 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 15:43:43 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"

// please.. don't
static void	oh_fuck(t_map *map, int hashcode, char *key, char *value);

void	map_insert(t_map *map, char *key, char *data)
{
	int code;

	code = hashcode(key);
	if (map->data[code] == 0)
		map->data[code] = data;
	else
		oh_fuck(map, code, key, data);
}

static void oh_fuck(t_map *map, int hashcode, char *key, char *value)
{
	
}