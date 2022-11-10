/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:31:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 17:55:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include "error.h"
#include <stdlib.h>

t_errdata	*get_errdata_singleton(void)
{
	static t_errdata	data = (t_errdata){
		.tokens = NULL,
		.is_tracing = false,
		.line = NULL,
	};

	return (&data);
}
