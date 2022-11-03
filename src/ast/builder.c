/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:35:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/03 13:53:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "ast_utils.h"
#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include "parser_utils.h"

t_node	*expr(t_token ***tokens);

t_node	*primary(t_token ***tokens)
{
	t_node		*inside;

	while (**tokens != NULL && (**tokens)->type == SPACE)
		(*tokens)++;
	if (**tokens == NULL)
		return (NULL);
	if ((**tokens)->type == PAREN_OPEN)
	{
		(*tokens)++;
		inside = expr(tokens);
		if (**tokens != NULL && (**tokens)->type == PAREN_CLOSE)
			(*tokens)++;
		else
			ft_printf("Expected ')'\n");
		return (inside);
	}
	else if (is_command_token(**tokens))
		return (wrap_command(create_command(tokens)));
	else
		ft_printf("Unexpected token\n");
	return (NULL);
}

t_node	*pipeline(t_token ***tokens)
{
	t_node	*node;

	node = primary(tokens);
	while (**tokens != NULL && (**tokens)->type == PIPE_TOKEN)
	{
		(*tokens)++;
		node = new_node(node, PIPE_NODE, primary(tokens));
	}
	return (node);
}

t_node	*expr(t_token ***tokens)
{
	t_node		*node;
	t_node_type	type;

	node = pipeline(tokens);
	while (**tokens != NULL
		&& ((**tokens)->type == OR_TOKEN
			|| (**tokens)->type == AND_TOKEN))
	{
		if ((**tokens)->type == OR_TOKEN)
			type = OR_NODE;
		else
			type = AND_NODE;
		(*tokens)++;
		node = new_node(node, type, pipeline(tokens));
	}
	return (node);
}

// AST Syntax
// expr -> pipeline ( ( "&&" | "||" ) pipeline )*
// pipeline -> primary ( "|" primary )*
// primary -> command | ( "(" expr ")" )
t_node	*build_tree(t_token **tokens)
{
	return (expr(&tokens));
}
