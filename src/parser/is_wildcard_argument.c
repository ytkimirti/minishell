/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wildcard_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:07:24 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/08 15:08:30 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

bool	is_wildcard_argument(t_token **token)
{
	while (*token != NULL && (*token)->type != SPACE_TOKEN)
	{
		if ((*token)->type == WILDCARD_TOKEN)
			return (true);
		token++;
	}
	return (false);
}
