/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:38:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 07:38:37 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "ast_utils.h"
#include "command.h"

int	walk_logic(t_node *tree, t_stdio std)
{
	if (tree->type == AND_NODE)
		return (walk_and(tree, std));
	else if (tree->type == OR_NODE)
		return (walk_or(tree, std));
	return (SHELL_ERROR);
}

int	walk_or(t_node *tree, t_stdio std)
{
	int	left_return;

	left_return = walk_tree(tree->left, std, true);
	if (left_return == SHELL_ERROR)
		return (SHELL_ERROR);
	if (left_return == 0)
		return (0);
	return (walk_tree(tree->right, std, true));
}

int	walk_and(t_node *tree, t_stdio std)
{
	int	left_return;

	left_return = walk_tree(tree->left, std, true);
	if (left_return != 0)
		return (left_return);
	return (walk_tree(tree->right, std, true));
}
