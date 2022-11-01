/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:30:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/31 15:04:49 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"
#include "hashing.h"
#include "map.h"
#include "env.h"
#include <stdlib.h>
#include "libft.h"

// NOTE: There are 20 chars of space at the end. Juuust to make sure.
// You know...
static t_envdata	*create_envdata(const char *key, const char *value)
{
	t_envdata	*data;
	char		*str;
	const int	buffer = 0;

	data = malloc(sizeof(t_envdata));
	if (data == NULL)
		return (NULL);
	data->len_key = ft_strlen(key);
	data->len_value = ft_strlen(value);
	str = malloc(sizeof(char) * (data->len_key + 1 + data->len_value
				+ 1 + buffer));
	data->capacity = data->len_key + 1 + data->len_value + 1 + buffer;
	ft_strlcpy(str, key, data->len_key + 1);
	ft_strlcpy(str + data->len_key + 1, value, data->len_value + 1);
	str[data->len_key] = '=';
	data->key = str;
	data->value = str + data->len_key + 1;
	return (data);
}

/*
 * Sets the value field of envdata
 */
void	set_envdata_value(t_envdata *data, const char *new_value)
{
	int		len_new;
	char	*new_str;
	int		i;

	len_new = ft_strlen(new_value);
	if (len_new + 1 > data->capacity - 1 - data->len_key)
	{
		new_str = malloc(sizeof(char) * (data->len_key + 1 + len_new + 1));
		i = 0;
		while (i < data->len_key + 1)
		{
			new_str[i] = data->key[i];
			i++;
		}
		i = 0;
		while (i < len_new + 1)
		{
			new_str[data->len_key + 1 + i] = new_value[i];
			i++;
		}
		free(data->key);
		data->key = new_str;
	}
	else
		ft_strlcpy(data->value, new_value, data->capacity - data->len_key - 1);
}

// TODO: Add error handling here
void	set_env(const char *key, const char *value)
{
	t_map		*map;
	t_envdata	*entry;
	t_hash		hash;

	map = get_env_singleton();
	hash = hashcode_str(key);
	entry = map_get(map, hash);
	if (entry == NULL)
	{
		entry = create_envdata(key, value);
		map_insert(map, hash, entry);
	}
	else
	{
		set_envdata_value(entry, value);
	}
}
