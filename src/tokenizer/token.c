/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/tokenizer/token.c
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:32:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 22:33:22 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

inline bool	is_printable(enum e_token_type type)
{
	return (type == WORD);
}
========
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
>>>>>>>> ast:src/ast/ast_utils.h
