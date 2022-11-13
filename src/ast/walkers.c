/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:03:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/13 14:52:03 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ast_utils.h"
#include "command.h"

int	walk_logic(t_node *tree, t_stdio std)
{
	if (tree->type == AND_NODE)
		return (walk_and(tree, std));
	else if (tree->type == OR_NODE)
		return (walk_or(tree, std));
	return (-1);
}

int	walk_tree(t_node *tree, t_stdio std, bool is_sync)
{
	int	pid;

	if (tree == NULL)
		return (1);
	if (tree->type == PIPE_NODE)
		return (walk_pipe(tree, std, is_sync));
	else if (tree->type == COMMAND_NODE)
		return (execute_command(tree->command, std, is_sync));
	else if (is_sync)
		return (walk_logic(tree, std));
	else
	{
		pid = fork();
		if (pid == 0)
		{
			walk_logic(tree, std);
			exit(0);
		}
		return (0);
	}
	return (-1);
}

int	walk_or(t_node *tree, t_stdio std)
{
	int	left_return;

	left_return = walk_tree(tree->left, std, true);
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

int	walk_pipe(t_node *tree, t_stdio std, bool is_sync)
{
	int		fds[2];
	int		right_return;

	pipe(fds);
	dprintf(2, "Walking pipe with %d -> [%d -> %d] -> %d\n", std.in, fds[1], fds[0], std.out);
	walk_tree(tree->left, (t_stdio){std.in, fds[1], std.err}, false);
	right_return = walk_tree(tree->right,
			(t_stdio){fds[0], std.out, std.err}, is_sync);
	return (right_return);
}
