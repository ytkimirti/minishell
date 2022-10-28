/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:47:17 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 14:18:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <stdlib.h>

void	map_remove(t_map *map, t_hash key, void (*del)(void *))
{
	int		index;
	t_entry	*entry;
	t_entry	*prev;
	t_entry	*next;

	index = key % map->size;
	if (map->entries[index] == NULL)
		return ;
	entry = map->entries[index];
	prev = NULL;
	while (entry != NULL)
	{
		if (entry->key == key)
		{
			next = entry->next;
			if (del != NULL && entry->value != NULL)
				del(entry->value);
			free(entry);
			if (prev != NULL)
				prev->next = next;
			else
				map->entries[index] = next;
			return ;
		}
		prev = entry;
		entry = entry->next;
	}
}
