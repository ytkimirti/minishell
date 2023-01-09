/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:02:17 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/09 16:12:19 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "env.h"

static const char	*select_func(t_envdata *data)
{
	return (data->key);
}

// static char	**merge_sort(char **arr, int first, int last)
// {
// 	int middle;
//
// 	middle = (first + last) / 2;
// 	if (first > last)
// 		return arr;
// 	if (last - first > 1)
// 	{
// 		merge_sort(arr, first, middle);
// 		merge_sort(arr, middle + 1 , last);
// 	}
// }
//
// static char	**sort_array(char **arr)
// {
// 	return (arr);
// }
//
char	**extract_env(void)
{
	t_map	*map;
	char	**envp;

	map = get_env_singleton();
	envp = (char **)map_select(map, (void *(*)(void *))select_func);
	return (envp);
}
