/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:45:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:09:11 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "error.h"
#include <stdlib.h>

t_node	*new_node(t_node *left, t_node_type type, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		malloc_error();
	node->type = type;
	node->command = NULL;
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*wrap_command(t_command *command)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		malloc_error();
	node->type = COMMAND_NODE;
	node->command = command;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
