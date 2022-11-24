/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:26:15 by emakas            #+#    #+#             */
/*   Updated: 2022/11/24 12:46:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H

# define BUILT_IN_H

# include "command.h"
# include "ast.h"

typedef int	(*t_builtin_func)(t_command *command, t_stdio std);

t_builtin_func	find_builtin_function(const char *name);

#endif
