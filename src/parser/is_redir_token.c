/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:07:04 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/26 11:38:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

bool	is_redir_token(t_token *token)
{
	return (token != NULL
		&& (token->type == REDIR_OUT
			|| token->type == REDIR_IN
			|| token->type == REDIR_APPEND
			|| token->type == REDIR_HEREDOC));
}
