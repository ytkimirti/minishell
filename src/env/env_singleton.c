/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_singleton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:32:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/01 12:07:22 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "env_utils.h"
#include <stdlib.h>

t_map	**get_env_doubleptr(void)
{
	static t_map	*map = NULL;

	return (&map);
}

void	free_envdata(t_envdata *data)
{
	free(data->key);
	free(data);
}

void	free_env_singleton(void)
{
	t_map	**map;

	map = get_env_doubleptr();
	if (*map == NULL)
		return ;
	destroy_map(*map, (void (*)(void *))free_envdata);
	*map = NULL;
}

t_map	*get_env_singleton(void)
{
	t_map	**map;

	map = get_env_doubleptr();
	if (*map == NULL)
		*map = create_map(64);
	return (*map);
}
