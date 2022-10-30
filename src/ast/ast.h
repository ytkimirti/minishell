/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:57:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/28 19:13:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H

# define AST_H

# include "command.h"
# include "tstdio.h"

typedef enum e_node_type
{
	PIPE,
	AND,
	OR,
	COMMAND
}	t_node_type;

typedef struct s_node
{
	char				*name;
	struct s_node		*left;
	struct s_node		*right;
	enum e_node_type	type;
	t_command			*command;
}	t_node;

t_node	*build_example_tree(void);
int		walk_tree(t_node *tree, t_stdio std);

#endif
