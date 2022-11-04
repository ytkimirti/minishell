/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:32:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 11:41:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "command_utils.h"
#include "libft.h"
#include "env.h"
#include "global.h"
#include "colors.h"

const char	*find_executable(const char *name)
{
	const char	*str;
	int			i;

	i = 0;
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