/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cached_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:42:58 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 11:45:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"
#include "vector.h"
#include <stdbool.h>

/*
 * Every path pointer is a t_cvec pointer
 */
typedef struct path_cache
{
	t_pvec	*paths;
	bool	is_empty;
}	t_path_cache;

static t_path_cache	*get_path_ptr(void)
{
	static t_path_cache	data = (t_path_cache){.is_empty = true};

	return (&data);
}

static void	fill_paths(const char *str, t_path_cache *data)
{
	int				i;
	t_cvec			*curr;

	i = 0;
	while (str[i] != '\0')
	{
		curr = cvec_new(128);
		while (str[i] != ':' && str[i] != '\0')
		{
			cvec_append(curr, str[i]);
			i++;
		}
		cvec_append(curr, '/');
		pvec_append(data->paths, curr);
		if (str[i] == ':')
			i++;
	}
}

static void	clear_cache(t_path_cache *cache)
{
	pvec_del(cache->paths, (void (*)(void *))cvec_del);
	cache->paths = NULL;
	cache->is_empty = true;
}

static void	update_path(void)
{
	t_path_cache	*data;
	const char		*str;

	data = get_path_ptr();
	if (!data->is_empty)
		clear_cache(data);
	data->paths = pvec_new(32);
	data->is_empty = false;
	str = get_env("PATH", 4);
	fill_paths(str, data);
}

const char	*get_joined_path(const char *executable_name, int index)
{
	int				orig_length;
	t_path_cache	*data;
	t_cvec			*cvec;

	data = get_path_ptr();
	if (data->is_empty)
		update_path();
	if (index >= data->paths->len)
		return (NULL);
	cvec = data->paths->arr[index];
	orig_length = cvec->len;
	cvec_appendstr(cvec, executable_name, true);
	cvec->len = orig_length;
	return (cvec->arr);
}
