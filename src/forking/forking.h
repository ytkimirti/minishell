/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:43:39 by emakas            #+#    #+#             */
/*   Updated: 2022/10/08 15:43:55 by emakas           ###   ########.fr       */
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

/**
 * @brief Runs executable function in different child proccess
 * Then returns executable exit status number.
 * If needed, standard input-output values changes in new proccess
 * 
 * @param stdio_new new io values to be changed
 * @param executable function to be called in new proccess
 * @return int exit status of executed proccess
 */
int	forknrun(t_stdio stdio_new, int (*executable)(t_command *cmd, char *envp));

#endif