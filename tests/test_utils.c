/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:17:31 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 17:40:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../src/tokenize_state.h"
#include "../src/token.h"
#include <string.h>

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
    	return a->len == b->len && a->type == b->type && strcmp(a->str, b->str) == 0;
	return (a->type == b->type);
}

char	*token_type_tostr(enum e_token_type type)
{
	if (type == WORD)
		return "WORD";
	if (type == SPACE)
		return "SPACE";
	if (type == QUOTE_OPEN)
		return "QUOTE_OPEN";
	if (type == QUOTE_CLOSE)
		return "QUOTE_CLOSE";
	if (type == SQUOTE_OPEN)
		return "SQUOTE_OPEN";
	if (type == SQUOTE_CLOSE)
		return "SQUOTE_CLOSE";
	if (type == PAREN_OPEN)
		return "PAREN_OPEN";
	if (type == PAREN_CLOSE)
		return "PAREN_CLOSE";
	if (type == EMPTY)
		return "EMPTY";
	return "UNKNOWN";
}

char *cr_user_t_token_tostr(t_token *token)
{
    char *out;

    cr_asprintf(&out, "(t_token) { .len = %d, .type = %s, .str = \"%s\" }",
			token->len, token_type_tostr(token->type), token->str);
    return out;
}

