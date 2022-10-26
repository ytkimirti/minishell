/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:05:11 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 16:18:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*create_node(t_node_type type, char *name, t_command *cmd, t_node *left, t_node *right)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->name = name;
	node->left = left;
	node->right = right;
	node->type = type;
	return (node);
}

int	ft_echo(t_command *command)
{
	printf("%s says hello!\n", command->argv[0]);
	return (0);
}

int	ft_false(t_command *command)
{
	printf("%s returned false\n", command->argv[0]);
	(void)command;
	return (1);
}

int	ft_true(t_command *command)
{
	printf("%s returned true\n", command->argv[0]);
	(void)command;
	return (0);
}

t_node	*build_example_tree()
{
	t_command a = {
		.argv = (char *[]){"a"},
		.execute = &ft_echo,
	};
	t_command b = {
		.argv = (char *[]){"b"},
		.execute = &ft_echo,
	};
	t_command c = {
		.argv = (char *[]){"c"},
		.execute = &ft_echo,
	};

	return (
			create_node(PIPE, "top_pipe", NULL,
				create_node(COMMAND, "a", &a, NULL, NULL),
				create_node(PIPE, "middle_pipe", NULL,
					create_node(COMMAND, "b", &b, NULL, NULL),
					create_node(COMMAND, "c", &c, NULL, NULL)
					)
				));
}

void	fake_pipe(int buf[2])
{
	static int	last_pipe = 10;

	buf[0] = last_pipe;
	buf[1] = last_pipe + 1;
	last_pipe += 2;
}

void	walk_tree(t_node *tree, int in, int out, int err)
{
	int	pipe[2];

	if (tree->type == PIPE)
		fake_pipe(pipe);
	else
	{
		pipe[0] = out;
		pipe[1] = in;
	}

	if (tree->type == COMMAND)
	{
		printf("%s: in: %d -> out: %d err: %d\n", tree->name, in, out, err);
		return ;
	}
	walk_tree(tree->left, in, pipe[0], err);
	walk_tree(tree->right, pipe[1], out, err);
}

int	main(void)
{
	t_node	*tree;

	tree = build_example_tree();

	walk_tree(tree, 0, 1, 2);
}
