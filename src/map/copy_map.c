/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:54:30 by emakas            #+#    #+#             */
/*   Updated: 2022/10/16 15:58:45 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	copy_map(t_map *map_dsr, t_map *map_src)
{
	ft_memcpy(map_dst->data,map_src->data, map_src->size);
}