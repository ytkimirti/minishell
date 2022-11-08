/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:58 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "map.h"
#include <stdlib.h>

void	**map_select(t_map *map, map_select_func func)
{
	void	**result;
	int		i;
	t_entry	*tmp;
	int		entry_index;

	result = malloc(sizeof(void *) * map->entry_count + 1);
	if (result == NULL)
		return (malloc_error());
	entry_index = 0;
	i = 0;
	while (i < map->size)
	{
		tmp = map->entries[i];
		while (tmp != NULL)
		{
			result[entry_index] = func(tmp->value);
			entry_index++;
			tmp = tmp->next;
		}
		i++;
	}
	result[entry_index] = NULL;
	return (result);
}
