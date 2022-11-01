/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:59 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/01 11:44:13 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_utils.h"

int	get_env_length(const char *key, int len)
{
	t_map		*map;
	t_envdata	*entry;

	map = get_env_singleton();
	entry = map_get(map, hashcode((void *)key, len));
	if (entry == NULL)
		return (0);
	return (entry->len_value);
}
