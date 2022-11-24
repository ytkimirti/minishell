/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:28:13 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/23 09:07:16 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H

# define ENV_UTILS_H

# include "map.h"
# include <stdbool.h>

/*
 * This is the internal struct that holds 
 * environment entries.
 *
 * The key thing is that key and value
 * point to the same string with length
 * len_key + 1 + len_value
 *
 * 	   value
 * 		|
 * USER=ytkimirti
 * |
 * key
 */
typedef struct s_envdata
{
	char	*key;
	int		len_key;
	char	*value;
	int		len_value;
	int		capacity;
	bool	is_allocated;
}	t_envdata;

/*
 * This function holds environment data
 * in it as a static variable.
 */
t_map	*get_env_singleton(void);

void	free_envdata(t_envdata *data);

#endif
