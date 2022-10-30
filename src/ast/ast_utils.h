/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:55:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 19:13:45 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_UTILS_H

# define AST_UTILS_H

# include "ast.h"
# include <stdbool.h>

int	walk_tree(t_node *tree, t_stdio std);
int	walk_or(t_node *tree, t_stdio std);
int	walk_and(t_node *tree, t_stdio std);
int	walk_pipe(t_node *tree, t_stdio std);

#endif
