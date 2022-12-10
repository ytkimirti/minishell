/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:25:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/10 13:39:37 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include "parser_utils.h"
#include "libft.h"
#include "vector.h"
#include "env.h"
#include <limits.h>
#include "error.h"
#include "wildcard.h"

/*
 * Expands token into string str.
 * Returns count of chars expanded
 */
static int	expand_token(t_token *token, char *str)
{
	if (token->type == WORD)
		return (strlencpy(str, token->str, token->len));
	if (token->type == VAR)
		return (strlencpy(str, get_env(token->str, token->len), INT_MAX));
	return (0);
}

typedef struct s_expand_state
{
	bool	in_squote;
	bool	in_quote;
}	t_expand_state;

static void	update_expand_state(t_expand_state *state, t_token_type type)
{
	if (type == SINGLE_QUOTE)
		state->in_squote = !state->in_squote;
	if (type == DOUBLE_QUOTE)
		state->in_quote = !state->in_quote;
}

char	*expand_tokens(t_token ***tokens)
{
	int				pos;
	char			*str;
	int				len;
	t_expand_state	state;

	len = length_tokens(*tokens);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	pos = 0;
	state = (t_expand_state){false, false};
	while (is_command_token(**tokens) && (**tokens)->type != SPACE_TOKEN
		&& !is_redir_token(**tokens) && !is_wildcard_token(**tokens))
	{
		update_expand_state(&state, (**tokens)->type);
		pos += expand_token(**tokens, str + pos);
		(*tokens)++;
	}
	if (!state.in_quote && !state.in_squote)
		return (str);
	if (state.in_squote)
		error_unexpected(**tokens, SINGLE_QUOTE);
	else if (state.in_quote)
		error_unexpected(**tokens, DOUBLE_QUOTE);
	free(str);
	return (NULL);
}

static void	parse_wildcard_part(t_token ***tokens, t_cvec *str)
{
	if (**tokens == NULL)
		return ;
	if ((**tokens)->type == WILDCARD_TOKEN)
		cvec_append(str, '*');
	if ((**tokens)->type == QUESTION_TOKEN)
		cvec_append(str, '?');
	while (is_wildcard_token(**tokens))
		(*tokens)++;
}

static void	insert_special_chars(char *str)
{
	while (*str != '\0')
	{
		if (*str == '?')
			*str = ESC_QUESTION_CHAR;
		else if (*str == '*')
			*str = ESC_WILDCARD_CHAR;
		str++;
	}
}

void	append_to_pvec(char **arr, t_pvec *vec)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		pvec_append(vec, arr[i]);
		i++;
	}
}

/*
 * TODO: Add the actual wildcard expansion to here
 */
bool	expand_wildcard_argument(t_token ***tokens, t_pvec *args_vec)
{
	t_cvec	*str;
	char	*tmp;
	char	**result;

	(void)args_vec;
	str = cvec_new(64);
	while (true)
	{
		parse_wildcard_part(tokens, str);
		if (!is_command_token(**tokens) || is_wildcard_token(**tokens))
			break ;
		tmp = expand_tokens(tokens);
		insert_special_chars(tmp);
		cvec_appendstr(str, tmp, false);
		parse_wildcard_part(tokens, str);
		if (!is_command_token(**tokens) || (**tokens)->type == SPACE_TOKEN)
			break ;
	}
	cvec_append(str, '\0');
	result = expand_wildcard(str->arr);
	free((free(str->arr), str));
	if (result == NULL)
		return (false);
	(free(result), append_to_pvec(result, args_vec));
	return (true);
}
