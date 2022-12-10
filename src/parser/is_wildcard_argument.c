/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wildcard_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:07:24 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/10 09:02:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "token.h"
#include <stdlib.h>

bool	is_wildcard_argument(t_token **token)
{
	while (*token != NULL && (*token)->type != SPACE_TOKEN)
	{
		if (is_wildcard_token(*token))
			return (true);
		token++;
	}
	return (false);
}
