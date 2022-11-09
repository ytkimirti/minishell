/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:35:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/09 17:51:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "ast_utils.h"
#include "error.h"
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "parser_utils.h"
#include "coz.h"

t_node	*primary(t_token ***tokens)
{
		COZ_PROGRESS;
	while (**tokens != NULL && (**tokens)->type == SPACE)
		(*tokens)++;
	if (**tokens == NULL)
		return (NULL);
	if ((**tokens)->type == PAREN_OPEN)
		return (primary_paren(tokens));
	else if (is_command_token(**tokens))
		return (primary_command(tokens));
	else
		error("Unexpected token");
	return (NULL);
}

t_node	*pipeline(t_token ***tokens)
{
		COZ_PROGRESS;
	t_node	*node;
	t_node	*tmp;

	node = primary(tokens);
	if (node == NULL)
		return (node);
	while (**tokens != NULL && (**tokens)->type == PIPE_TOKEN)
	{
		(*tokens)++;
		tmp = primary(tokens);
		if (tmp == NULL)
			break ;
		node = new_node(node, PIPE_NODE, tmp);
	}
	return (node);
}

t_node	*expr(t_token ***tokens)
{
		COZ_PROGRESS;
	t_node		*node;
	t_node		*tmp;
	t_node_type	type;

	node = pipeline(tokens);
	if (node == NULL)
		return (node);
	while (**tokens != NULL
		&& ((**tokens)->type == OR_TOKEN
			|| (**tokens)->type == AND_TOKEN))
	{
		if ((**tokens)->type == OR_TOKEN)
			type = OR_NODE;
		else
			type = AND_NODE;
		(*tokens)++;
		tmp = pipeline(tokens);
		if (tmp == NULL)
			break ;
		node = new_node(node, type, tmp);
	}
	return (node);
}

// AST Syntax
// expr -> pipeline ( ( "&&" | "||" ) pipeline )*
// pipeline -> primary ( "|" primary )*
// primary -> command | ( "(" expr ")" )
t_node	*build_tree(t_token **tokens)
{
		COZ_PROGRESS;
	return (expr(&tokens));
}
