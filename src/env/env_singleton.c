/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_singleton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:32:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/31 14:35:48 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "env_utils.h"

t_map	*get_env_singleton(void)
{
	static t_map	*map = NULL;

	if (map == NULL)
		map = create_map(64);
	return (map);
}
