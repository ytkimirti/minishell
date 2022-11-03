/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:03:52 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 17:29:49 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map.h"
#include "env_utils.h"
#include <stdlib.h>

/*
 * Returns false if no = character is found
 */
static bool	divide_string(char *str, int *len_key, int *len_value)
{
	int		i;
	bool	found_key;

	i = 0;
	found_key = false;
	while (str[i] != '\0')
	{
		if (!found_key && str[i] == '=')
		{
			*len_key = i;
			found_key = true;
		}
		i++;
	}
	if (!found_key)
		return (false);
	*len_value = i - *len_key - 1;
	return (true);
}

static void	insert_env_noalloc(char *str)
{
	t_map		*map;
	t_envdata	*data;
	int			len_key;
	int			len_value;

	if (!divide_string(str, &len_key, &len_value))
		return ;
	map = get_env_singleton();
	data = malloc(sizeof(t_envdata));
	if (data == NULL)
		return ;
	data->len_key = len_key;
	data->len_value = len_value;
	data->is_allocated = false;
	data->key = str;
	data->value = str + (len_key + 1);
	data->capacity = len_key + 1 + len_value + 1;
	map_insert(map, hashcode(str, len_key), data);
}

void	init_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		insert_env_noalloc(envp[i]);
		i++;
	}
}
