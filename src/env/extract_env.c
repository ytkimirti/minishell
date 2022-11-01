/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:02:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/01 11:19:40 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "env.h"

static const char	*select_func(t_envdata *data)
{
	return (data->key);
}

char	**extract_env(void)
{
	t_map	*map;

	map = get_env_singleton();
	return ((char **)map_select(map, (void *(*)(void *))select_func));
}
