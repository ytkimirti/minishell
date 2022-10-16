/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:51:50 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 15:53:19 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"

char	*map_get(t_map *map, char *key)
{
	int code;

	code = hashcode(key);
	if (code < map->size)
		return (map->data[code]);
}