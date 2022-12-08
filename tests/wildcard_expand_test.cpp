#include <cstring>
#include <functional>
#include <stdlib.h>
#include <string.h>
#include <string>
extern "C"
{
#include "hashing.h"
#include "utils.h"
#include "token.h"
#include "tokenize_state.h"
#include "tokenizer.h"
#include "tokenizer_funcs.h"
#include "colors.h"
#include "map.h"
#include "wildcard.h"
#include "wildcard_utils.h"
#include "libft.h"
}
#include "gtest/gtest.h"
#include "test_utils.hpp"
#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include <algorithm>

struct WildcardData
{
	std::string pattern;
	std::vector<std::string> expected;
};


class WildcardDirectoryChecker: public testing::TestWithParam<WildcardData> {};

std::ostream& operator<<(std::ostream& stream, const WildcardData& data)
{
	
	stream << YEL;
	stream << "pattern: " << data.pattern << std::endl;
	stream << RST;
	
	return stream;
}

TEST_P(WildcardDirectoryChecker, DirectoryChecking)
{
	WildcardData data = GetParam();
	t_token	mock_token;

	mock_token.len = data.pattern.length();
	mock_token.str = data.pattern.c_str();

	char	**result_pointer = expand_wildcard(&mock_token);
	std::vector<std::string> result = std::vector<std::string>();

	for (int i = 0; result_pointer[i] != NULL; i++)
	{
		result.push_back(std::string(result_pointer[i]));
		free(result_pointer[i]);
	}
	free(result_pointer);

    std::sort(result.begin(), result.end());
    std::sort(data.expected.begin(), data.expected.end());
	EXPECT_EQ(data.expected, result);
}


INSTANTIATE_TEST_SUITE_P(DirectoryChecking, WildcardDirectoryChecker, testing::Values(
	WildcardData { "tests/dirs/code/Make*", std::vector<std::string>{
		"tests/dirs/code/Makefile"
	}},
	WildcardData { "tests/dirs/code/*.c", std::vector<std::string>{
		"tests/dirs/code/main.c",
		"tests/dirs/code/other.c",
	}},
	WildcardData { "tests/dirs/code/*.*.js", std::vector<std::string>{
		"tests/dirs/code/other.config.js",
		"tests/dirs/code/thing.config.js",
	}},
	WildcardData { "tests/dirs/*/ensar", std::vector<std::string>{
		"tests/dirs/code/ensar",
		"tests/dirs/names/ensar",
	}}
));
