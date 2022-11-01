/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:35:57 by emakas            #+#    #+#             */
/*   Updated: 2022/11/01 11:11:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <unistd.h>
#include <stdlib.h>

void	map_insert(t_map *map, t_hash key, void *value)
{
	int		index;
	t_entry	*entry;
	t_entry	*tmp;

	entry = malloc(sizeof(t_entry));
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	index = key % map->size;
	map->entry_count++;
	if (map->entries[index] == NULL)
		map->entries[index] = entry;
	else
	{
		tmp = map->entries[index];
		map->entries[index] = entry;
		entry->next = tmp;
	}
}
