/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:35:01 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/23 21:43:02 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tokenize_state.h"
#include "token.h"
#include "tokenizer.h"
#include <string.h>
#include "test_utils.h"

Test(tokenizer, basic)
{
	char	*str;

	str = strdup("hello  world");
	t_token correct[3] = (t_token[]){
		{ .len = 5, .type = WORD, .str = "hello" },
		{ .type = SPACE },
		{ .len = 5, .type = WORD, .str = "world" },
	};

	t_token **out = tokenize(str);

	for (int i = 0; i < 3; i++)
		cr_expect(eq(type(t_token), *out[i], correct[i]));
	free_tokens(out);
	free(str);
}
Test(tokenizer, three_word_special)
{
	char	*str;

	str = strdup("hello _world_");
	t_token correct[3] = (t_token[]){
		{ .len = 5, .type = WORD, .str = "hello" },
		{ .type = SPACE },
		{ .len = 7, .type = WORD, .str = "_world_" },
	};

	t_token **out = tokenize(str);

	for (int i = 0; i < 3; i++)
		cr_expect(eq(type(t_token), *out[i], correct[i]));
	free_tokens(out);
	free(str);
}
Test(tokenizer, with_space)
{
	char	*str;

	str = strdup("  hello  world");
	t_token correct[4] = (t_token[]){
		{ .type = SPACE },
		{ .len = 5, .type = WORD, .str = "hello" },
		{ .type = SPACE },
		{ .len = 5, .type = WORD, .str = "world" },
	};

	t_token **out = tokenize(str);

	for (int i = 0; i < 4; i++)
		cr_expect(eq(type(t_token), *out[i], correct[i]));
	free_tokens(out);
	free(str);
}
