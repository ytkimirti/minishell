/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:59 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 08:58:16 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_utils.h"

const char	*get_env(const char *key, int len)
{
	t_map		*map;
	t_envdata	*entry;

	map = get_env_singleton();
	entry = map_get(map, hashcode((void *)key, len));
	if (entry == NULL)
		return ("");
	return (entry->value);
}
