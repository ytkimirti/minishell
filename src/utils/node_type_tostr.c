/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_type_tostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:03:25 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 13:05:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "colors.h"
#include <stdlib.h>

char	*node_type_tostr(t_node_type type)
{
	if (type == AND_NODE)
		return ("AND");
	if (type == OR_NODE)
		return ("OR");
	if (type == PIPE_NODE)
		return ("PIPE");
	if (type == COMMAND_NODE)
		return ("COMMAND");
	return ("UNKNOWN");
}
