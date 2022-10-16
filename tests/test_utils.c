/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:17:31 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/16 12:32:23 by ykimirti         ###   ########.tr       */
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

// Declarations
t_token	*tokenize_word(char **str, t_state *state);

void	reset_state(void)
{
	g_state.in_quotes = false;
}

/* We need to provide basic functions for our dummy struct */
int cr_user_t_token_eq(t_token *a, t_token *b)
{
	if (a->type == WORD && b->type == WORD)
    	return a->len == b->len && a->type == b->type && memcmp(a->str, b->str, a->len) == 0;
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

	token_str = dup_token_str(token);

    cr_asprintf(&out, "(t_token) { .len = %d, .type = %s, .str = \"%s\" }",
			token->len, token_type_tostr(token->type), token_str);

	free(token_str);
    return out;
}

