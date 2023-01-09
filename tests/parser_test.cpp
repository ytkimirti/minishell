#include <cstring>
#include <string.h>
#include <string>
extern "C" 
{
#include "utils.h"
#include "tokenize_state.h"
#include "tokenizer.h"
#include "tokenizer_funcs.h"
#include "colors.h"
#include "command.h"
#include "parser.h"
#include "env.h"
}
#include "test_utils.hpp"
#include "gtest/gtest.h"

struct DummyCommandData
{
	std::string					input;
	std::vector<std::string>	argv;
	std::string					in_file;
	std::string					out_file;
	bool						is_append;
	bool						is_heredoc;

	// This prevents gtest from outputting nonsense hexadecimal output
	friend std::ostream& operator<<(std::ostream& os, const DummyCommandData& bar) {
		return os;
	}
};

class ParserTest : public testing::TestWithParam<DummyCommandData> {
	void SetUp()
	{
		free_env_singleton();
		set_env("foo", "bar");
		set_env("bar", "foo");
		set_env("user", "mehmet");
		set_env("under_score", "is_nice");
		set_env("spaced", " <hello world> ");
	}
};

void	fill_dummy_command(t_command *cmd, DummyCommandData &data)
{
	cmd->argv = (char **)malloc(sizeof(char *) * (data.argv.size() + 1));
	for (int i = 0; i < data.argv.size(); i++)
	{
		cmd->argv[i] = (char *)data.argv[i].c_str();
	}
	cmd->argv[data.argv.size()] = NULL;
	cmd->argc = data.argv.size();

	// if (data.out_file.empty())
	// 	cmd->out_file = NULL;
	// else
	// 	cmd->out_file = (char *)data.out_file.c_str();
	//
	// if (data.in_file.empty())
	// 	cmd->in_file = NULL;
	// else
	// 	cmd->in_file = (char *)data.in_file.c_str();
	// cmd->is_append = data.is_append;
	// cmd->is_heredoc = data.is_heredoc;
}

void	free_dummy_command(t_command *cmd)
{
	free(cmd->argv);
}

TEST_P(ParserTest, Handle)
{
	t_command	*command;
	t_token		**tokens;
	t_token		**tmp_tokens;
	t_command	correct;
	const char	*str;

	DummyCommandData data = GetParam();

	fill_dummy_command(&correct, data);

	str = data.input.c_str();
	tokens = tokenize(str);

	ASSERT_NE(tokens, nullptr) << "tokenizer returned null" << std::endl << "input: " << str;
	int i = 0;

	tmp_tokens = tokens;
	command = create_command(&tmp_tokens);

	EXPECT_EQ(*command, correct);

	//i is the length
	int out_length = i;

	if (!(*command == correct))
	{
		printf("INPUT: " YEL "\"%s\"" RST "\n", str);
		printf(BYEL "----- TOKENS OUTPUT -----\n" RST);
		for (int i = 0; tokens[i] != NULL; i++)
		{
			std::cout << *tokens[i] << std::endl;
		}
		FAIL();
	}

	free_dummy_command(&correct);
	free_tokens(tokens);
}

INSTANTIATE_TEST_SUITE_P(Tokenizer, ParserTest, testing::Values(
			DummyCommandData{
				.input = "ahmet>  file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "file",
				.is_append = false,
			},
			DummyCommandData{
				.input = "ahmet>file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "file",
				.is_append = false,
			},
			DummyCommandData{
				.input = "ahmet >file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "file",
				.is_append = false,
			},
			DummyCommandData{
				.input = "ahmet <file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.in_file = "file",
				.is_append = false,
			},
			DummyCommandData{
				.input = "ahmet >>file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "file",
				.is_append = true,
			},
			DummyCommandData{
				.input = "ahmet <<file",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.in_file = "file",
				.is_heredoc = true,
			},
			DummyCommandData{
				.input = "<<EOF ahmet",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.in_file = "EOF",
				.is_heredoc = true,
			},
			DummyCommandData{
				.input = "ahmet <\"a space\"",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.in_file = "a space",
				.is_append = false,
			},
			DummyCommandData{
				.input = "ahmet >>$foo$foo",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "barbar",
				.is_append = true,
			},
			DummyCommandData{
				.input = "ahmet >>$foo$foo$asdas$asdlkfja $foo",
				.argv = std::vector<std::string>{
					"ahmet",
					"bar",
				},
				.out_file = "barbar",
				.is_append = true,
			},
			DummyCommandData{
				.input = "ahmet >>\"I said $foo\"\" bwuh\"",
				.argv = std::vector<std::string>{
					"ahmet",
				},
				.out_file = "I said bar bwuh",
				.is_append = true,
			},

			DummyCommandData{
				.input = "hello world",
				.argv = std::vector<std::string>{
					"hello",
					"world"
				},
			},
			DummyCommandData{
				.input = "hello world   ",
				.argv = std::vector<std::string>{
					"hello",
					"world"
				},
			},
			DummyCommandData{
				.input = "echo \"hello world\"",
				.argv = std::vector<std::string>{
					"echo",
					"hello world"
				},
			},
			DummyCommandData{
				.input = "\" ()|<>?asd\\ \"",
				.argv = std::vector<std::string>{
					" ()|<>?asd\\ ",
				},
			},
			DummyCommandData{
				.input = "oh my $god",
				.argv = std::vector<std::string>{
					"oh",
					"my",
					"",
				},
			},
			DummyCommandData{
				.input = "heyoo \"()\") continues here",
				.argv = std::vector<std::string>{
					"heyoo",
					"()"
				},
			},
			DummyCommandData{
				.input = "heyoo \"()\"| continues here",
				.argv = std::vector<std::string>{
					"heyoo",
					"()"
				},
			},
			DummyCommandData{
				.input = "heyoo \"()\"&& continues here",
				.argv = std::vector<std::string>{
					"heyoo",
					"()"
				},
			},
			DummyCommandData{
				.input = "heyoo \"()\")| continues here",
				.argv = std::vector<std::string>{
					"heyoo",
					"()"
				},
			},
			DummyCommandData{
				.input = "hello $foo",
				.argv = std::vector<std::string>{
					"hello",
					"bar"
				},
			},
			DummyCommandData{
				.input = "hello $bar",
				.argv = std::vector<std::string>{
					"hello",
					"foo"
				},
			},
			DummyCommandData{
				.input = "hello $nonexistingnev",
				.argv = std::vector<std::string>{
					"hello",
					""
				},
			},
			DummyCommandData{
				.input = "hello $foo$bar",
				.argv = std::vector<std::string>{
					"hello",
					"barfoo"
				},
			},
			DummyCommandData{
				.input = "hello $foo $bar",
				.argv = std::vector<std::string>{
					"hello",
					"bar",
					"foo"
				},
			},
			DummyCommandData{
				.input = "hello \"my fav is|$foo|man\"   ",
				.argv = std::vector<std::string>{
					"hello",
					"my fav is|bar|man",
				},
			},
			DummyCommandData{
				.input = "hello $spaced$bar",
				.argv = std::vector<std::string>{
					"hello",
					" <hello world> foo",
				},
			}
			));
