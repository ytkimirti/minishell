/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 18:33:49 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include "error.h"
#include <stdlib.h>

void	begin_trace(t_token **tokens)
{
	t_errdata	*data;

	data = get_errdata_singleton();
	data->is_tracing = false;
	data->tokens = tokens;
}

void	end_trace(void)
{
	t_errdata	*data;

	data = get_errdata_singleton();
	data->is_tracing = false;
	data->tokens = NULL;
}
