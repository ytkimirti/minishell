/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:59 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 09:11:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_utils.h"

void	unset_env(const char *key, int len)
{
	t_map		*map;

	map = get_env_singleton();
	map_remove(map, hashcode((void *)key, len), (void (*)(void *))free_envdata);
}
