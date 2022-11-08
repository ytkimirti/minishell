/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:53:06 by emakas            #+#    #+#             */
/*   Updated: 2022/11/01 11:10:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

t_map	*create_map(int size)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->entries = malloc(sizeof(t_entry *) * size);
	if (map->entries == NULL)
		return (NULL);
	ft_bzero(map->entries, sizeof(t_entry *) * size);
	map->size = size;
	map->entry_count = 0;
	return (map);
}
