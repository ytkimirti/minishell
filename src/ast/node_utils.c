/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:45:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 13:46:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

t_node	*new_node(t_node *left, t_node_type type, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->type = type;
	node->command = NULL;
	node->left = left;
	node->right = right;
	node->name = NULL;
	return (node);
}

t_node	*wrap_command(t_command *command)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->type = COMMAND_NODE;
	node->command = command;
	node->left = NULL;
	node->right = NULL;
	node->name = NULL;
	return (node);
}
