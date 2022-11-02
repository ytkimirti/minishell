/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:07:04 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 16:21:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

bool	is_command_token(t_token *token)
{
	return (token != NULL
		&& token->type != PIPE_TOKEN
		&& token->type != PAREN_OPEN
		&& token->type != PAREN_CLOSE
		&& token->type != AND_TOKEN
		&& token->type != OR_TOKEN);
}
