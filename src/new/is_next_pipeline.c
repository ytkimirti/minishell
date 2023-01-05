/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:45:52 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/05 19:22:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "new_utils.h"
#include "parser_utils.h"
#include <unistd.h>

bool	is_next_pipeline(t_token **tokens)
{
	t_token	**jumped;

	jumped = jump_primary(tokens);
	if (*jumped == NULL)
		return (false);
	return ((*jumped)->type == PIPE_TOKEN);
}
