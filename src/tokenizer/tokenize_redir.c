/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/07 15:41:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "libft.h"

// TODO: Finish implementing this m8
t_token	*tokenize_redir(char **str, t_state *state)
{
	t_token	*token;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	if (**str == '<')
		token->type = REDIR_IN;
	else if (**str == '>')
	{
		if ((*str)[1] == '>')
		{
			token->type = REDIR_APPEND;
			(*str)++;
		}
		else
			token->type = REDIR_OUT;
	}
	(*str)++;
	return (token);
}
