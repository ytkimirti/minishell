/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:26:45 by emakas            #+#    #+#             */
/*   Updated: 2022/11/24 21:32:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <unistd.h>
#include <stdlib.h>

static void	destroy_all_entries(t_entry *entry, void (*del)(void *))
{
	t_entry	*tmp;

	while (entry != NULL)
	{
		if (entry->value != NULL)
			del(entry->value);
		tmp = entry;
		entry = entry->next;
		free(tmp);
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
