/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:32:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/17 18:51:03 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "env.h"

const char	*find_executable(const char *name)
{
	const char	*str;
	int			i;

	i = 0;
	if (name != NULL && (name[0] == '.' || name[0] == '/'))
		return (name);
	while (true)
	{
		str = get_joined_path(name, i);
		if (str == NULL)
			break ;
		if (access(str, X_OK) == 0)
			return (str);
		i++;
	}
	return (NULL);
}
