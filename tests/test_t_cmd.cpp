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

class SampleCommand
{

};

class CommandTest : public testing::TestWithParam<SampleCommand>
{
	void SetUp()
	{
		// Reset state here
		state.in_quotes = false;
	}

protected:
	t_state state;
};

TEST_P(CommandTest, HandleInQuotes)
{
	
	EXPECT_EQ("SELAM","SELAM");

}