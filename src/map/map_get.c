/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:51:50 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 14:15:23 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <stdlib.h>

void	*map_get(t_map *map, t_hash key)
{
	int		index;
	t_entry	*entry;

	index = key % map->size;
	if (map->entries[index] == NULL)
		return (NULL);
	entry = map->entries[index];
	while (entry != NULL)
	{
		if (entry->key == key)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}
