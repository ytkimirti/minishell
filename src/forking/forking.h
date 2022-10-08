/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:43:39 by emakas            #+#    #+#             */
/*   Updated: 2022/10/08 14:55:40 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Purpose of this functionality is, abstracting forking and running
	proccess. So, whenever command is started in shell, some utilities
	like forking new proccess, duplicating standart io and recieving
	last command execution status is handling automatically.
	
 */

#ifndef FORKING_H
# define FORKING_H
# include "../command/command.h"

struct s_stdio
{
	int	in;
	int	out;
	int	err;
};

typedef struct s_stdio	t_stdio;

int	forknrun(t_stdio stdio_new, int (*executable)(t_command *cmd, char *envp));

#endif