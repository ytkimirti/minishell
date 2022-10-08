/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:35:01 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/08 18:20:04 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../src/tokenize_state.h"
#include "../src/token.h"
#include "../src/tokenizer.h"
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

	printf("Before except\n");
	cr_expect(eq(type(t_token)[1], *out, correct));

	printf("Freeing all...\n");
	int i = 0;
	while (out[i] != NULL)
	{
		free(out[i]);
		i++;
	}
	printf("Freeing all...\n");
	free(str);
}
// Test(tokenizer, three_word_special)
// {
// 	char	*str;
//
// 	str = strdup("hello _world_");
// 	t_token correct[3] = (t_token[]){
// 		{ .len = 5, .type = WORD, .str = "hello" },
// 		{ .type = SPACE },
// 		{ .len = 7, .type = WORD, .str = "_world_" },
// 	};
//
// 	t_token **out = tokenize(str);
//
// 	cr_expect(eq(type(t_token)[3], *out, correct));
// 	free_tokens(out);
// 	free(str);
// }
// Test(tokenizer, with_space)
// {
// 	char	*str;
//
// 	str = strdup("  hello  world");
// 	t_token correct[4] = (t_token[]){
// 		{ .type = SPACE },
// 		{ .len = 5, .type = WORD, .str = "hello" },
// 		{ .type = SPACE },
// 		{ .len = 5, .type = WORD, .str = "world" },
// 	};
//
// 	t_token **out = tokenize(str);
//
// 	cr_expect(eq(type(t_token)[4], *out, correct));
// 	free_tokens(out);
// 	free(str);
// }
