/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstdio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:59:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 07:45:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSTDIO_H

# define TSTDIO_H

# include "vector.h"

/*
 * Unwanted_fds are the file descriptors
 * you MUST close after you fork and dup2
 *
 * If you don't close them, because of the
 * other references to these filedescriptors
 * some SIGPIPES or EOF would not be sent.
 */
typedef struct s_stdio
{
	int		in;
	int		out;
	int		err;
	t_ivec	*unwanted_fds;
}	t_stdio;

#endif
