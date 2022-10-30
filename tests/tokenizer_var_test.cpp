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

struct TokenizeVarTestData
{
	const char	*input;
	t_token correct;
	e_token_type type;
	bool	in_quotes = false;

	TokenizeVarTestData(char *input, char *correct, e_token_type type = VAR, bool in_quotes = false)
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

class TokenizeVarTest : public testing::TestWithParam<TokenizeVarTestData> {
	void SetUp()
	{
		// Reset state here
		state.in_quotes = false;
		state.in_squotes = false;
	}

	protected:
		t_state state;
};

TEST_P(TokenizeVarTest, HandleInQuotes)
{
	TokenizeVarTestData data = GetParam();

	state.in_quotes = data.in_quotes;
	const char *tmp = data.input;
	t_token	*out = tokenize_var(&tmp, &state);


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

INSTANTIATE_TEST_SUITE_P(OneWordOutside, TokenizeVarTest, testing::Values(
			TokenizeVarTestData((char *)"$ahmet", (char *)"ahmet"),
			TokenizeVarTestData((char *)"$", (char *)""),
			TokenizeVarTestData((char *)"$,,,", (char *)""),
			TokenizeVarTestData((char *)"$ahmet_mehmet", (char *)"ahmet_mehmet"),
			TokenizeVarTestData((char *)"$ahmet$", (char *)"ahmet"),
			// TokenizeVarTestData((char *)"$$", (char *)"$"),
			TokenizeVarTestData((char *)"$#", (char *)"#"),
			TokenizeVarTestData((char *)"$1", (char *)"1"),
			TokenizeVarTestData((char *)"$9", (char *)"9"),
			TokenizeVarTestData((char *)"$12", (char *)"1"),
			TokenizeVarTestData((char *)"$?", (char *)"?")
			));

INSTANTIATE_TEST_SUITE_P(OneWordInside, TokenizeVarTest, testing::Values(
			TokenizeVarTestData((char *)"$ahmet", (char *)"ahmet", VAR, true),
			TokenizeVarTestData((char *)"$ahmet\"mehmet", (char *)"ahmet", VAR, true),
			TokenizeVarTestData((char *)"$\"mehmet", (char *)"", VAR, true),
			TokenizeVarTestData((char *)"$", (char *)"", VAR, true),
			TokenizeVarTestData((char *)"$,,,", (char *)"", VAR, true),
			TokenizeVarTestData((char *)"$ahmet_mehmet", (char *)"ahmet_mehmet", VAR, true),
			TokenizeVarTestData((char *)"$ahmet$", (char *)"ahmet", VAR, true),
			// TokenizeVarTestData((char *)"$$", (char *)"$", VAR, true),
			TokenizeVarTestData((char *)"$#", (char *)"#", VAR, true),
			TokenizeVarTestData((char *)"$1", (char *)"1", VAR, true),
			TokenizeVarTestData((char *)"$9", (char *)"9", VAR, true),
			TokenizeVarTestData((char *)"$12", (char *)"1", VAR, true),
			TokenizeVarTestData((char *)"$?", (char *)"?", VAR, true)
			));





