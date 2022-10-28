/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:26:45 by emakas            #+#    #+#             */
/*   Updated: 2022/10/28 08:21:49 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>
#include <stdlib.h>

static void	destroy_all_entries(t_entry *entry, void (*del)(void *))
{
	while (entry != NULL)
	{
		if (entry->value != NULL)
			del(entry->value);
		free(entry);
		entry = entry->next;
	}
}

void	destroy_map(t_map *map, void (*del)(void *))
{
	int		i;

	if (map == NULL)
		return ;
	i = 0;
	if (map->entries != NULL)
	{
		while (i < map->size)
		{
			if (map->entries[i] != NULL)
				destroy_all_entries(map->entries[i], del);
			i++;
		}
		free(map->entries);
	}
	free(map);
}
