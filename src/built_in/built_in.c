/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:23:18 by emakas            #+#    #+#             */
/*   Updated: 2022/11/24 12:45:55 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "built_in.h"
#include "builtin_funcs.h"
#include "libft.h"
#include "tstdio.h"

t_builtin_func	find_builtin_function(const char *name)
{
	if (ft_strncmp(name, "echo", sizeof("echo")) == 0)
		return (ft_echo);
	if (ft_strncmp(name, "path", sizeof("path")) == 0)
		return (ft_path);
	if (ft_strncmp(name, "cd", sizeof("cd")) == 0)
		return (ft_cd);
	if (ft_strncmp(name, "pwd", sizeof("pwd")) == 0)
		return (ft_pwd);
	if (ft_strncmp(name, "exit", sizeof("exit")) == 0)
		return (ft_exit);
	if (ft_strncmp(name, "env", sizeof("env")) == 0)
		return (ft_env);
	if (ft_strncmp(name, "export", sizeof("export")) == 0)
		return (ft_export);
	if (ft_strncmp(name, "unset", sizeof("unset")) == 0)
		return (ft_unset);
	return (NULL);
}
