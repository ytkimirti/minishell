/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:17:31 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/16 14:28:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tokenize_state.h"
#include "token.h"
#include "utils.h"
#include "parser.h"
#include "executer.h"
#include "libft.h"
#include <string.h>
#include <stdio.h> 

t_state	g_state;

void	reset_state(void)
{
	g_state.in_quotes = false;
}

int cr_user_t_token_eq(t_token *a, t_token *b)
{
	if (a == b)
		return (true);
	if (a == NULL || b == NULL)
		return (false);
	if (a->type == WORD && b->type == WORD)
	{
		bool str_match = false;
		if (a->len <= 0)
			cr_log_warn("Length of token a is %d but it's type is WORD\n", a->len);
		if (b->len <= 0)
			cr_log_warn("Length of token b is %d but it's type is WORD\n", a->len);
		if (a->len != b->len)
			return (false);
		if (a->len < 0 || b->len < 0)
			return (false);
		if (a->str != NULL && b->str != NULL)
			str_match = memcmp(a->str, b->str, a->len) == 0;
    	return str_match;
	}
	return (a->type == b->type);
}

int cr_user_t_cmd_eq(t_cmd *a, t_cmd *b)
{
	return (false);
	int	i;

    if (a->argc == b->argc && strcmp(a->path, b->path) == 0)
	{
		i = 0;
		while (i < a->argc)
		{
			if (strcmp(a->argv[i], b->argv[i]) != 0)
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

char *cr_user_t_cmd_tostr(t_cmd *cmd)
{
    char	*out;

	char	*argv_str;
	char	*tmp;
	char	*new_arg;
	int		i;

	argv_str = strdup("");
	i = 0;
	while (i < cmd->argc)
	{
		asprintf(&new_arg, i == cmd->argc - 1 ? "\"%s\"" : "\"%s\", ", cmd->argv[i]);

		tmp = argv_str;
		argv_str = ft_strjoin(argv_str, new_arg);
		printf("Arv string is >%s<\n", argv_str);
		free(tmp);
		free(new_arg);

		i++;
	}

    cr_asprintf(&out, "(t_cmd) { .path = %s, .argc = %d, .argv = [%s]",
			cmd->path, cmd->argc, argv_str);

	free(argv_str);
    return out;
}

char *cr_user_t_token_tostr(t_token *token)
{
    char	*out;
	char	*token_str;
	bool	token_allocated;

	if (token == NULL)
	{
		cr_asprintf(&out, "NULL");
		return (out);
	}
	else if (!token->type | PRINTABLE)
	{
		cr_asprintf(&out, "(t_token) { .type = %s }", token_type_tostr(token->type));
		return (out);
	}

	token_allocated = false;
	if (token->len < 0)
		token_str = "<corrupt>";
	else if (token->str == NULL)
		token_str = "<null>";
	else
	{
		token_str = dup_token_str(token);
		token_allocated = true;
	}

    cr_asprintf(&out, "(t_token) { .len = %d, .type = %s, .str = \"%s\" }",
			token->len, token_type_tostr(token->type), token_str);

	if (token_allocated)
		free(token_str);
    return out;
}

