/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:57:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/13 14:43:57 by ykimirti         ###   ########.tr       */
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
 * Walks a given tree starting from the leftmost deepest node.
 * When is_sync is true, it waits until the command is finishes
 * and uses it's exit status.
 *
 * If it's false it continues without waiting for it to finish.
 * For example:
 *
 *
 * ((echo "Hello!" | tr a-z A-Z) | cat ) && echo "DONE!"
 *
 *                AND (sync)
 *                 |
 *             |--------------------|
 *             |                    |
 *           PIPE (sync)         COMMAND (sync)
 *             |
 *        |-------------|
 *        |             |
 *      PIPE (async)   CMD (sync)
 *        |
 *    |------------|
 *   CMD (async)   CMD (async)
 *
 *
 * Async pipes and commands doesn't require extra forks, they
 * just don't wait for the right command to finish.
 *
 * Async AND's and OR's fork themselves before running. The still
 * wait for the left one to finish but because of the fork, it doesn't
 * cause the main thread to wait.
 */
int		walk_tree(t_node *tree, t_stdio std, bool is_sync);

void	free_tree(t_node *tree);

#endif
