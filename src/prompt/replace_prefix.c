/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:37:32 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 12:09:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_prefix(const char *str,
		const char *prefix,
		const char *new_prefix)
{
	int			len_prefix;
	int			len_str;
	int			len_new_prefix;
	char		*new;

	len_str = ft_strlen(str);
	len_prefix = ft_strlen(prefix);
	len_new_prefix = ft_strlen(new_prefix);
	if (ft_strncmp(str, prefix, len_prefix) == 0)
	{
		new = malloc(len_str - len_prefix + len_new_prefix + 1);
		ft_strlcpy(new, new_prefix, len_new_prefix + 1);
		ft_strlcpy(new + len_new_prefix,
			str + len_prefix, len_str - len_prefix + 1);
		return (new);
	}
	return (NULL);
}
