#include <cstring>
#include <string.h>
#include <string>
extern "C" 
{
#include "utils.h"
#include "token.h"
#include "tokenize_state.h"
#include "tokenizer.h"
#include "tokenizer_funcs.h"
#include "colors.h"
}
#include "test_utils.hpp"
#include "gtest/gtest.h"
#include "../libs/googletest/googletest/include/gtest/gtest.h"

struct TokenizeTestData
{
	const char	*input;
	t_token correct;
	e_token_type type;
	bool	in_quotes = false;

	TokenizeTestData(char *input, char *correct, e_token_type type = WORD, bool in_quotes = false)
	{
		this->input = input;
		this->type = type;
		this->in_quotes = in_quotes;
		this->correct = t_token{
			.len = (int)strlen(correct),
			.type = type,
			.str = correct,
		};

	}
};

class TokenizeWordTest : public testing::TestWithParam<TokenizeTestData> {
	void SetUp()
	{
		// Reset state here
		state.in_quotes = false;
	}

	protected:
		t_state state;
};

TEST_P(TokenizeWordTest, HandleInQuotes)
{
	TokenizeTestData data = GetParam();

	state.in_quotes = data.in_quotes;
	const char *tmp = data.input;
	t_token	*out = tokenize_word(&tmp, &state);


	EXPECT_EQ(*out, data.correct);

	if (data.correct.type == WORD)
	{
		// If it's a WORD, it should move the pointer length characters
		// asd
		// |    
		//
		// "asd "
		//	   |
		EXPECT_EQ(tmp, out->str + out->len);
	}
	free(out);
}

INSTANTIATE_TEST_SUITE_P(OneWordOutside, TokenizeWordTest, testing::Values(
			TokenizeTestData((char *)"__asd__", (char *)"__asd__"),
			TokenizeTestData((char *)"  hello", (char *)""),
			TokenizeTestData((char *)"hello    ", (char *)"hello"),
			TokenizeTestData((char *)"müşevğ  ", (char *)"müşevğ")
			));

INSTANTIATE_TEST_SUITE_P(OneWordInside, TokenizeWordTest, testing::Values(
			TokenizeTestData((char *)"  mehmet  ", (char *)"  mehmet  ",  WORD, true)
			));
INSTANTIATE_TEST_SUITE_P(DoesNotEscape, TokenizeWordTest, testing::Values(
			TokenizeTestData((char *)"as\"as", (char *)"as",  WORD, true),
			TokenizeTestData((char *)"\"as\"as", (char *)"",  WORD, true),
			TokenizeTestData((char *)"not escaped\\\"bwuh", (char *)"not escaped\\",  WORD, true)
			));
