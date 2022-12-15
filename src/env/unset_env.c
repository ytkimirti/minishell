/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:59 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/15 15:06:38 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_utils.h"
#include "libft.h"

void	unset_env(const char *key, int len)
{
	t_map		*map;

	map = get_env_singleton();
	map_remove(map, hashcode((void *)key, len), (void (*)(void *))free_envdata);
	if (ft_strncmp(key, "PATH", sizeof("PATH")) == 0)
		update_path();
}
