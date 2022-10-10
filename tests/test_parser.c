/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:35:01 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/09 13:28:26 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../src/tokenize_state.h"
#include "../src/token.h"
#include "../src/tokenizer.h"
#include "../src/parser.h"
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

	t_cmd *out = create_cmd(tokens);
	cr_expect(eq(type(t_cmd), *out, correct));

	free_tokens(tokens);
	free_cmd(out);
}
