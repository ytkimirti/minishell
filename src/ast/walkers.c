/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:03:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 21:08:25 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ast_utils.h"
#include "command.h"
#include "vector.h"
#include <assert.h>

int	execute_tree(t_node *root)
{
	t_ivec	*unwanted_fds;
	int		status;

	unwanted_fds = ivec_new(16);
	status = walk_tree(root, (t_stdio){0, 1, 2, unwanted_fds}, true);
	ivec_del(unwanted_fds);
	return (status);
}

int	walk_tree(t_node *tree, t_stdio std, bool is_sync)
{
	int	pid;

	if (tree == NULL)
		return (SHELL_ERROR);
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
	int		right_return;

	if (pipe(fds) == -1)
	{
		perror("creating pipe failed");
		return (SHELL_ERROR);
	}
	ivec_append(std.unwanted_fds, fds[0]);
	ivec_append(std.unwanted_fds, fds[1]);
	left_return = walk_tree(tree->left,
			(t_stdio){std.in, fds[1], std.err, std.unwanted_fds}, false);
	if (left_return == SHELL_ERROR)
		return (SHELL_ERROR);
	assert(std.unwanted_fds->len >= 1);
	std.unwanted_fds->len--;
	close(fds[1]);
	right_return = walk_tree(tree->right,
			(t_stdio){fds[0], std.out, std.err, std.unwanted_fds}, is_sync);
	assert(std.unwanted_fds->len >= 1);
	std.unwanted_fds->len--;
	close(fds[0]);
	return (right_return);
}
