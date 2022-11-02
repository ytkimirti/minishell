/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:35:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 15:39:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "parser.h"

// ( a && (b || c) )
//
// a && b || c
// The guaranteed thing is that when
// you finish parsing a function. You
// get a control structure.
//
//
t_node	*build_tree(t_token **tokens)
{
	t_command	*left;

	left = create_command(&tokens);

}
