/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 19:25:46 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include "error.h"
#include <stdlib.h>
#include <assert.h>

void	begin_trace(t_token **tokens, char *line)
{
	t_errdata	*data;

	data = get_errdata_singleton();
	data->is_tracing = false;
	data->tokens = tokens;
	assert(line != NULL);
	data->line = line;
}

void	end_trace(void)
{
	t_errdata	*data;

	data = get_errdata_singleton();
	data->is_tracing = false;
	data->tokens = NULL;
	data->line = NULL;
}
