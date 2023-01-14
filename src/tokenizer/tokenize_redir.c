/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/14 12:27:09 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "libft.h"
#include "error.h"

static void	tokenize_out(t_token *token, char **str)
{
	if ((*str)[1] == '>')
	{
		token->type = REDIR_APPEND;
		(*str)++;
	}
	else
		token->type = REDIR_OUT;
}

static void	tokenize_in(t_token *token, char **str)
{
	if ((*str)[1] == '<')
	{
		token->type = REDIR_HEREDOC;
		(*str)++;
	}
	else
		token->type = REDIR_IN;
}

// TODO: Finish implementing this m8
t_token	*tokenize_redir(char **str, t_state *state)
{
	t_token	*token;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	token->len = 0;
	if (**str == '<')
		tokenize_in(token, str);
	else if (**str == '>')
		tokenize_out(token, str);
	(*str)++;
	return (token);
}
