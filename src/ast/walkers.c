/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:03:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 11:39:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ast_utils.h"
#include "command.h"

int	walk_tree(t_node *tree, t_stdio std)
{
	if (tree->type == PIPE_NODE)
		walk_pipe(tree, std);
	else if (tree->type == AND_NODE)
		walk_and(tree, std);
	else if (tree->type == OR_NODE)
		walk_or(tree, std);
	else if (tree->type == COMMAND_NODE)
		execute_command(tree->command, std, false);
	return (-1);
}

int	walk_or(t_node *tree, t_stdio std)
{
	int	left_return;

	left_return = walk_tree(tree->left, std);
	if (left_return == 0)
		return (0);
	return (walk_tree(tree->right, std));
}

int	walk_and(t_node *tree, t_stdio std)
{
	int	left_return;

	left_return = walk_tree(tree->left, std);
	if (left_return != 0)
		return (left_return);
	return (walk_tree(tree->right, std));
}

int	walk_pipe(t_node *tree, t_stdio std)
{
	int		fds[2];
	int		pid;
	int		right_return;

	pipe(fds);
	pid = 0;
	if (tree->left->type == COMMAND_NODE)
		execute_command(tree->left->command,
			(t_stdio){std.in, fds[1], std.err}, true);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			walk_tree(tree->left,
				(t_stdio){std.in, fds[1], std.err});
			exit(0);
		}
	}
	right_return = walk_tree(tree->right,
			(t_stdio){fds[0], std.out, std.err});
	if (pid != 0)
		kill(pid, SIGKILL);
	return (right_return);
}
