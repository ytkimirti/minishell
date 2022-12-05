#include <cstring>
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
	stream << "expected:" << std::endl;
	for (int i = 0; i < data.expected.size(); i++){
		stream << "\t" << data.expected.at(i);
	}
	stream << RST;
	
	return stream;
}

TEST_P(WildcardDirectoryChecker, DirectoryChecking)
{
	WildcardData data = GetParam();
	t_token	mock_token;

	mock_token.len = data.pattern.length();
	mock_token.str = data.pattern.c_str();

	char	**result = expand_wildcard(&mock_token);
	int len = 0;
	while (result[len] != NULL)
		len++;

	EXPECT_EQ(len, data.expected.size());

	int	i = 0;
	while (result[i] != NULL && i < data.expected.size())
	{
		EXPECT_EQ(std::string(result[i]), data.expected.at(i));
		i++;
	}
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
