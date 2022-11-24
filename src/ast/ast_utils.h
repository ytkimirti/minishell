/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:55:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 21:12:33 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_UTILS_H

# define AST_UTILS_H

# include "ast.h"
# include <stdbool.h>

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
 *
 * Notice there can be errors emited execute time.
 * But because t_command's are not connected to a token, they can't be
 * pretty printed. When an error occurs this returns SHELL_ERROR
 */
int		walk_tree(t_node *tree, t_stdio std, bool is_sync);

int		walk_logic(t_node *tree, t_stdio std);
int		walk_or(t_node *tree, t_stdio std);
int		walk_and(t_node *tree, t_stdio std);
int		walk_pipe(t_node *tree, t_stdio std, bool is_sync);
void	print_tree(t_node *root);

t_node	*new_node(t_node *left, t_node_type type, t_node *right);

t_node	*wrap_command(t_command *command);

t_node	*primary_paren(t_token ***tokens);

t_node	*primary_command(t_token ***tokens);

/*
 * Builds an expression from given tokens using recursive ast parser.
 * It's basically the actual build_tree function.
 */
t_node	*expr(t_token ***tokens);

/*
 * Returns false if one of the closes fail.
 */
bool	close_unwanted(t_ivec *fds);

#endif
