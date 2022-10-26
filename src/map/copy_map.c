/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:54:30 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 12:35:29 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	copy_map(t_map *map_dst, t_map *map_src)
{
	ft_memcpy(map_dst->entries, map_src->entries, map_src->size);
}
