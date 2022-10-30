/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/prompt/git_status_utils.h
/*   git_status_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:16:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 11:16:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIT_STATUS_UTILS_H

# define GIT_STATUS_UTILS_H

char	*handle_git_output(int fd);
========
/*   tstdio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:59:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 18:59:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_H

# define STDIO_H

typedef struct s_stdio
{
	int	in;
	int	out;
	int	err;
}	t_stdio;
>>>>>>>> ast:src/ast/tstdio.h

#endif
