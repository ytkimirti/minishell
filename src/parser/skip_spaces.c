/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:04:48 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/11 08:27:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parser_utils.h"
#include <stdlib.h>

void	skip_spaces(t_token ***tokens)
{
	while ((**tokens) != NULL && (**tokens)->type == SPACE)
		(*tokens)++;
}
