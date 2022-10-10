/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:38:20 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/10 22:49:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tokenize_state.h"
#include "token.h"
#include <string.h>
#include "test_utils.h"

Test(tokenize_word, basic, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("Hello");
	correct = (t_token){
		.len = 5,
		.type = WORD,
		.str = str
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}

Test(tokenize_word, basic2, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("Hello  ");
	correct = (t_token){
		.len = 5,
		.type = WORD,
		.str = "Hello"
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}

Test(tokenize_word, basic3, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("Hello<>ASd");
	correct = (t_token){
		.len = 5,
		.type = WORD,
		.str = "Hello"
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}

Test(tokenize_word, error1, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("<Hello<>ASd");
	correct = (t_token){
		.len = 0,
		.type = WORD,
		.str = ""
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, error2, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("  Hello<>ASd");
	correct = (t_token){
		.len = 0,
		.type = WORD,
		.str = ""
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, error3, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	str = strdup("");
	correct = (t_token){
		.len = 0,
		.type = WORD,
		.str = ""
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}

Test(tokenize_word, in_quote_basic, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	g_state.in_quotes = true;
	str = strdup("Hello");
	correct = (t_token){
		.len = 5,
		.type = WORD,
		.str = "Hello"
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, in_quote_basic2, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	g_state.in_quotes = true;
	str = strdup("Hello >W o r<!");
	correct = (t_token){
		.len = 14,
		.type = WORD,
		.str = str
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, in_quote_basic3, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	g_state.in_quotes = true;
	str = strdup("<>()\\heyo");
	correct = (t_token){
		.len = 9,
		.type = WORD,
		.str = str
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, in_quote_dollar, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	g_state.in_quotes = true;
	str = strdup("Hello $USER");
	correct = (t_token){
		.len = 6,
		.type = WORD,
		.str = "Hello "
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
Test(tokenize_word, in_quote_dollar2, .init=reset_state)
{
	char	*str;
	t_token	correct;
	t_token	*out;

	g_state.in_quotes = true;
	str = strdup(" Hel$INHERElo  ");
	correct = (t_token){
		.len = 4,
		.type = WORD,
		.str = " Hel"
	};

	out = tokenize_word(&str, &g_state);

	cr_expect(eq(type(t_token), *out, correct));
	free(out);
}
