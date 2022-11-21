/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:57:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/21 07:34:55 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H

# define AST_H

# include "command.h"
# include "tstdio.h"

typedef enum e_node_type
{
	PIPE_NODE,
	AND_NODE,
	OR_NODE,
	COMMAND_NODE,
}	t_node_type;

typedef struct s_node
{
	struct s_node		*left;
	struct s_node		*right;
	enum e_node_type	type;
	t_command			*command;
}	t_node;

t_node	*build_example_tree(void);

t_node	*build_tree(t_token **tokens);

/*
 * Executes a tree using walk_tree in the background
 * but this is a simpler facade for main.
 */
int		execute_tree(t_node	*root);

/*
 * This is the value returned by walk_tree or any other
 * walker function in case of an error caused by creation
 * of pipes, not finding the file etc.
 *
 * Since all other programs can only return from 0 - 255
 * this can't be used elsewhere.
 */
# define SHELL_ERROR 425

void	free_tree(t_node *tree);

#endif
