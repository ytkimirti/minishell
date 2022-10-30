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

struct DummyToken
{
	std::string str;
	enum e_token_type type;
};

struct TokenizeAllData
{
	std::string				input;
	std::vector<DummyToken>	correct_tokens;
};

class TokenizeAllTest : public testing::TestWithParam<TokenizeAllData> {
};

TEST_P(TokenizeAllTest, Handle)
{
	TokenizeAllData data = GetParam();

	const char *str = data.input.c_str();
	t_token	**out = tokenize(str);

	int i = 0;

	while (out[i] != NULL)
	{
		EXPECT_TRUE(i < data.correct_tokens.size()) << "There are extra tokens outputted";

		t_token correct;
		DummyToken &dummy = data.correct_tokens[i];

		correct.type = dummy.type;
		correct.str = dummy.str.c_str();
		correct.len = dummy.str.length();

		EXPECT_EQ(*out[i], correct);
		i++;
	}

	//i is the length
	int out_length = i;

	if (out_length != data.correct_tokens.size())
	{
		printf(RED "Lengths does not match! Expected: %d Got: %d\n" RST, (int)data.correct_tokens.size(), out_length);
		printf("INPUT: " YEL "\"%s\"" RST "\n", str);
		printf(BYEL "----- OUTPUT -----\n" RST);
		for (int i = 0; out[i] != NULL; i++)
		{
			std::cout << *out[i] << std::endl;
		}
		printf(BYEL "----- CORRECT -----\n" RST);
		for (int i = 0; i < data.correct_tokens.size(); i++)
		{
			t_token correct;
			DummyToken &dummy = data.correct_tokens[i];

			correct.type = dummy.type;
			correct.str = dummy.str.c_str();
			correct.len = dummy.str.length();
			// print_token(&correct);
			std::cout << correct << std::endl;
		}
		FAIL();
	}

	free_tokens(out);
}

INSTANTIATE_TEST_SUITE_P(OneWordOutside, TokenizeAllTest, testing::Values(
			TokenizeAllData{
				.input = "hello world",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"hello", WORD},
					DummyToken{"", SPACE},
					DummyToken{"world", WORD},
				}
			}));