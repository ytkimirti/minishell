/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:23:18 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 15:40:40 by emakas           ###   ########.fr       */
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
int	(*get_builtin(t_cmdtype type))(t_command *command, char **args)
{
	if (type == CD)
		return (ft_cd);
	else if (type == ECHO)
		return (ft_echo);
	else if (type == ENV)
		return (ft_env);
	else if (type == EXIT)
		return (ft_exit);
	else if (type == EXPORT)
		return (ft_export);
	else if (type == PWD)
		return (ft_pwd);
	else if (type == UNSET)
		return (ft_unset);
	else
		return (NULL);
}

t_cmdtype get_ebin(t_token *token)
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
		return (EXEC);
}
