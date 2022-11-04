/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 12:05:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

void	free_tree(t_node	*tree)
{
	if (tree->left)
		free_tree(tree->left);
	if (tree->right)
		free_tree(tree->right);
	if (tree->type == COMMAND_NODE)
		free_command(tree->command);
	free(tree);
}
