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
#include <unistd.h>
#include <stdlib.h>

void	destroy_map(t_map *map, void (*del)(void *))
{
    int     i;
    t_entry *entry;

	if (map == NULL)
        return ;
    i = 0;
    if (map->entries != NULL)
    {
        while (i < map->size)
        {
            if (map->entries[i] != NULL)
            {
                entry = map->entries[i];
                while (entry != NULL)
                {
                    if (entry->value != NULL)
                        del(entry->value);
                    free(entry);
                    entry = entry->next;
                }
            }
            i++;
        }
    }
    if (map->entries != NULL)
        free(map->entries);
    free(map);
}