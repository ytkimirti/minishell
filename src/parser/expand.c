/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:25:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:26 by ykimirti         ###   ########.tr       */
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

static void	parse_wildcard_part(t_token ***tokens, t_cvec *str)
{
	while (is_wildcard_token(**tokens))
	{
		if ((**tokens)->type == WILDCARD_TOKEN)
			cvec_append(str, '*');
		if ((**tokens)->type == QUESTION_TOKEN)
			cvec_append(str, '?');
		(*tokens)++;
	}
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
		if (!is_command_token(**tokens) || (**tokens)->type == SPACE_TOKEN)
			break ;
		tmp = expand_tokens(tokens);
		insert_special_chars(tmp);
		cvec_appendstr(str, tmp, false);
		free(tmp);
	}
	cvec_append(str, '\0');
	result = expand_wildcard(str->arr);
	free((free(str->arr), str));
	if (result == NULL)
		return (false);
	(append_to_pvec(result, args_vec),free(result));
	return (true);
}
