/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:53:06 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 14:31:35 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "hashing.h"
#include <stdlib.h>
#include <unistd.h>
#include "../../libft/libft.h" // BUNLAR NİYE HATALI :(

t_map	*create_map(int size)
{
	t_map	*map;
	char	**data;

	map = (t_map *) malloc(sizeof(t_map));
	if (map == 0)
		return (map);
	data = (char **) malloc(sizeof(char *) * size);
	if (data == 0)
		return (0);
	ft_bzero(data,size);
	map->data = data;
	map->size = size;
	return (map);
}
