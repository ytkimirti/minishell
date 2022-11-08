/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:55:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 17:52:56 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_UTILS_H

# define AST_UTILS_H

# include "ast.h"
# include <stdbool.h>

int		walk_tree(t_node *tree, t_stdio std);
int		walk_or(t_node *tree, t_stdio std);
int		walk_and(t_node *tree, t_stdio std);
int		walk_pipe(t_node *tree, t_stdio std);
void	print_tree(t_node *root);

t_node	*new_node(t_node *left, t_node_type type, t_node *right);

t_node	*wrap_command(t_command *command);

t_node	*primary_paren(t_token ***tokens);

t_node	*primary_command(t_token ***tokens);

t_node	*expr(t_token ***tokens);

#endif
