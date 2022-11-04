/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:29:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 00:12:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_UTILS_H

# define COMMAND_UTILS_H

/*
 * Tries to find executable in path. If found, returns
 * the path of the executable. Else returns NULL
 */
const char	*find_executable(const char *name);

#endif
