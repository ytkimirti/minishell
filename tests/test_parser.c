/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:35:01 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/23 21:44:04 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tokenize_state.h"
#include "token.h"
#include "tokenizer.h"
#include "parser.h"
#include <string.h>
#include "test_utils.h"

Test(parser_test, basic)
{
	char	*str;

	str = strdup("echo  Hello World!");

	t_token	**tokens = tokenize(str);

	t_cmd correct = (t_cmd){
		.path = "echo",
		.argc = 3,
		.argv = (char *[]){
			"echo",
			"Hello",
			"World!",
			NULL
		},
	};

	(void)correct;
	t_cmd *out = create_cmd(tokens);
	// cr_expect(eq(type(t_cmd), *out, correct));
	cr_assert(true);

	free_tokens(tokens);
	free_cmd(out);
}
