/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:47:17 by emakas            #+#    #+#             */
/*   Updated: 2022/11/01 11:11:17 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <stdlib.h>

static void	remove_entry(t_entry *prev, t_entry *entry,
		void (*del)(void *))
{
	t_entry	*next;

	next = entry->next;
	if (del != NULL && entry->value != NULL)
		del(entry->value);
	free(entry);
	if (prev != NULL)
		prev->next = next;
}

void	map_remove(t_map *map, t_hash key, void (*del)(void *))
{
	int		index;
	t_entry	*entry;
	t_entry	*prev;

	index = key % map->size;
	if (map->entries[index] == NULL)
		return ;
	entry = map->entries[index];
	prev = NULL;
	while (entry != NULL)
	{
		if (entry->key == key)
		{
			if (prev == NULL)
				map->entries[index] = entry->next;
			remove_entry(prev, entry, del);
			map->entry_count--;
			return ;
		}
		prev = entry;
		entry = entry->next;
	}
}
