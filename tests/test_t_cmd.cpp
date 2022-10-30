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

struct SampleCommand
{
	std::string msg;
};

class CommandTest : public testing::TestWithParam<SampleCommand>
{
	void SetUp()
	{
	}
};

TEST_P(CommandTest, HandleInQuotes)
{
	SampleCommand data = GetParam();

	EXPECT_EQ("SELAM","SELAM");
}

INSTANTIATE_TEST_SUITE_P(SelamVerEfenim, CommandTest, testing::Values(
				SampleCommand{
					.msg = "selaaam"
				}
			));
