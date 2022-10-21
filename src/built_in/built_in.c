/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:23:18 by emakas            #+#    #+#             */
/*   Updated: 2022/10/21 15:48:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include <unistd.h>
#include "libft.h"
/**
 * @brief Gets the builtin command execution function
 * 
 * @param id 
 * @return int(*)(t_command* command, char** args) function pointer for command execution
 */
int	(*get_builtin(e_built_ins built_in))(t_command *command, char **args)
{
	if (built_in == CD)
		return (ft_cd);
	else if (built_in == ECHO)
		return (ft_echo);
	else if (built_in == ENV)
		return (ft_env);
	else if (built_in == EXIT)
		return (ft_exit);
	else if (built_in == EXPORT)
		return (ft_export);
	else if (built_in == PWD)
		return (ft_pwd);
	else if (built_in == UNSET)
		return (ft_unset);
	else
		return (NULL);
}

e_built_ins get_ebin(t_token *token)
{
	if (ft_strncmp("cd", token->str, token->len) == 0)
		return (CD);
	else if (ft_strncmp("echo", token->str, token->len) == 0)
		return (ECHO);
	else if (ft_strncmp("env", token->str, token->len) == 0)
		return (ENV);
	else if (ft_strncmp("exit", token->str, token->len) == 0)
		return (EXIT);
	else if (ft_strncmp("export", token->str, token->len) == 0)
		return (EXPORT);
	else if (ft_strncmp("pwd", token->str, token->len) == 0)
		return (PWD);
	else if (ft_strncmp("unset", token->str, token->len) == 0)
		return (UNSET);
	else
		return (NONE);
}
