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

	ASSERT_NE(out, nullptr) << "tokenizer returned null" << std::endl << "input: " << str;
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
		printf("INPUT: " MAG "\"" YEL "%s" MAG "\"" RST "\n", str);
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

INSTANTIATE_TEST_SUITE_P(Tokenizer, TokenizeAllTest, testing::Values(
			TokenizeAllData{
				.input = "<file <<file <<<file >file >>file >>>file",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", REDIR_IN},
					DummyToken{"file", WORD},

					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_HEREDOC},
					DummyToken{"file", WORD},

					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_HEREDOC},
					DummyToken{"", REDIR_IN},
					DummyToken{"file", WORD},

					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_OUT},
					DummyToken{"file", WORD},

					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_APPEND},
					DummyToken{"file", WORD},

					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_APPEND},
					DummyToken{"", REDIR_OUT},
					DummyToken{"file", WORD},
				}
			},
			TokenizeAllData{
				.input = "ahmet >>file",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"ahmet", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_APPEND},
					DummyToken{"file", WORD},
				}
			},
			TokenizeAllData{
				.input = "ahmet>>file",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"ahmet", WORD},
					DummyToken{"", REDIR_APPEND},
					DummyToken{"file", WORD},
				}
			},
			TokenizeAllData{
				.input = "hello world",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"hello", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"world", WORD},
				}
			},
			TokenizeAllData{
				.input = "  asd $home$mehmet",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"asd", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"home", VAR},
					DummyToken{"mehmet", VAR},
				}
			},
			TokenizeAllData{
				.input = "heyo 'no $expansion ok|()?'",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"heyo", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"no $expansion ok|()?", WORD},
					DummyToken{"", SINGLE_QUOTE},
				}
			},
			TokenizeAllData{
				.input = "heyo\"inside\"ahmet",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"heyo", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"inside", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"ahmet", WORD},
				}
			},
			TokenizeAllData{
				.input = "\" asd $home asd \"ahmet",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{" asd ", WORD},
					DummyToken{"home", VAR},
					DummyToken{" asd ", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"ahmet", WORD},
				}
			},
			TokenizeAllData{
				.input = "\' asd $home asd \'ahmet",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{" asd $home asd ", WORD},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"ahmet", WORD},
				}
			},
			TokenizeAllData{
				.input = "(ahmet)",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", PAREN_OPEN},
					DummyToken{"ahmet", WORD},
					DummyToken{"", PAREN_CLOSE},
				}
			},
			TokenizeAllData{
				.input = "\"()\")| continues",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"()", WORD},
					DummyToken{"", DOUBLE_QUOTE},

					DummyToken{"", PAREN_CLOSE},
					DummyToken{"", PIPE_TOKEN},

					DummyToken{"", SPACE_TOKEN},

					DummyToken{"continues", WORD},
				}
			},
			TokenizeAllData{
				.input = "hello (bwuh >file) | echo||cat&&|",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"hello", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", PAREN_OPEN},
					DummyToken{"bwuh", WORD},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", REDIR_OUT},
					DummyToken{"file", WORD},
					DummyToken{"", PAREN_CLOSE},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"", PIPE_TOKEN},
					DummyToken{"", SPACE_TOKEN},
					DummyToken{"echo", WORD},
					DummyToken{"", OR_TOKEN},
					DummyToken{"cat", WORD},
					DummyToken{"", AND_TOKEN},
					DummyToken{"", PIPE_TOKEN},
				}
			},
			TokenizeAllData{
				.input = "aaa*bbb",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"aaa", WORD},
					DummyToken{"", WILDCARD_TOKEN},
					DummyToken{"bbb", WORD},
				}
			},
			TokenizeAllData{
				.input = "aaa**bbb",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"aaa", WORD},
					DummyToken{"", WILDCARD_TOKEN},
					DummyToken{"", WILDCARD_TOKEN},
					DummyToken{"bbb", WORD},
				}
			},
			TokenizeAllData{
				.input = "aaa\"**\"bbb",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"aaa", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"**", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"bbb", WORD},
				}
			},
			TokenizeAllData{
				.input = "aaa\'**\'bbb",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"aaa", WORD},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"**", WORD},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"bbb", WORD},
				}
			},
			TokenizeAllData{
				.input = "*aaa\"**\"bbb*",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", WILDCARD_TOKEN},
					DummyToken{"aaa", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"**", WORD},
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"bbb", WORD},
					DummyToken{"", WILDCARD_TOKEN},
				}
			},
			TokenizeAllData{
				.input = "?",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", QUESTION_TOKEN},
				}
			},
			TokenizeAllData{
				.input = "aaa\'??\'bbb",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"aaa", WORD},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"??", WORD},
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"bbb", WORD},
				}
			},
			TokenizeAllData{
				.input = "$[",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"$[", WORD},
				}
			},
			TokenizeAllData{
				.input = "$",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"$", WORD},
				}
			},
			TokenizeAllData{
				.input = "\"$[\"",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", DOUBLE_QUOTE},
					DummyToken{"$[", WORD},
					DummyToken{"", DOUBLE_QUOTE},
				}
			},
			TokenizeAllData{
				.input = "\'$[\'",
				.correct_tokens = std::vector<DummyToken>{
					DummyToken{"", SINGLE_QUOTE},
					DummyToken{"$[", WORD},
					DummyToken{"", SINGLE_QUOTE},
				}
			}
			));
