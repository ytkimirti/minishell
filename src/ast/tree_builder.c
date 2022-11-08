/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:05:11 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 13:16:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "ast_utils.h"
#include "command.h"
#include "libft.h"

// t_node	*create_node(t_node_type type, char *name,
// t_command *cmd, t_node *left, t_node *right)
// {
// 	t_node	*node;
//
// 	node = (t_node *)malloc(sizeof(t_node));
// 	node->name = name;
// 	node->left = left;
// 	node->right = right;
// 	node->type = type;
// 	node->command = cmd;
// 	return (node);
// }

t_command	*create_dummy_command(char *name, char *arg1)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->argc = 2;
	cmd->argv = malloc(sizeof(char *) * 3);
	cmd->argv[0] = ft_strdup(name);
	cmd->argv[1] = ft_strdup(arg1);
	cmd->argv[2] = NULL;
	cmd->out_file = NULL;
	cmd->in_file = NULL;
	cmd->is_append = false;
	return (cmd);
}

// t_node	*build_example_tree()
// {
// 	t_command *a, *b, *c;
// 	a = create_dummy_command("echo", "hello world");
// 	b = create_dummy_command("echo", "asdf");
// 	c = create_dummy_command("echo", "asdfasdf");
//
// 	return (
// 			create_node(PIPE, "top_pipe", NULL,
// 				create_node(COMMAND, "a", a, NULL, NULL),
// 				create_node(PIPE, "middle_pipe", NULL,
// 					create_node(COMMAND, "b", b, NULL, NULL),
// 					create_node(COMMAND, "c", c, NULL, NULL)
// 					)
// 				));
// }
//
// int	main(void)
// {
// 	t_node	*tree;
//
// 	tree = build_example_tree();
// 	walk_tree(tree, (t_stdio){0, 1, 2}, false);
// }
