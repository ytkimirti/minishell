/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_status_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:16:18 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 11:44:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "git_status_utils.h"
#include "prompt_utils.h"

#ifndef NO_GIT

char	*handle_git_output(int fd)
{
	char	*line;
	char	*res;
	int		len_line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len_line = ft_strlen(line);
	if (len_line > 0 && line[len_line - 1] == '\n')
		line[len_line - 1] = '\0';
	res = replace_prefix(line, "refs/heads/", "");
	if (res == NULL)
		res = line;
	else
		free(line);
	return (res);
}

#endif
