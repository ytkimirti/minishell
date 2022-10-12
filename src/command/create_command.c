/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:03 by emakas            #+#    #+#             */
/*   Updated: 2022/10/12 15:00:11 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static t_command	*create_system_command(t_token **tokens);
static t_command	*create_builtin_command(t_token **tokens);

t_command	*create_command(t_token **tokens)
{
	char	*command;
	int		index;

	index = 0;
	while (tokens[index] != 0)
	{}
}

static t_command	*create_system_command(t_token **tokens)
{}

static t_command	*create_builtin_command(t_token **tokens)
{}