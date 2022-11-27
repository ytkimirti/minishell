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
}
#include "gtest/gtest.h"
#include "test_utils.hpp"
#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include <algorithm>

struct WildcardData
{
	std::string str;
	std::string pattern;
	bool expected;
};

std::ostream& operator<<(std::ostream& stream, const WildcardData& data)
{
	std::string string_bool = data.expected ? "true" : "false";
	stream << YEL;
	stream << "string: " << data.str << ", ";
	stream << "pattern: " << data.pattern << ", ";
	stream << "expected: " << string_bool;
	stream << RST;
	
	return stream;
}


class WildcardTest : public testing::TestWithParam<WildcardData> {
};

TEST_P(WildcardTest, PatternMatching)
{
	WildcardData data = GetParam();
	ASSERT_EQ(check_match((char *)data.str.c_str(), (char *)data.pattern.c_str()),data.expected);
}

INSTANTIATE_TEST_SUITE_P(PatternsMatching, WildcardTest, testing::Values(
	WildcardData { "Desktop", "*", true },
	WildcardData { "Desktop", "*e*", true },
	WildcardData { "Desktop", "*k*", true },
	WildcardData { "Desktop", "*p", true },
	WildcardData { "Desktop", "*e*p", true },
	WildcardData { "Desktop", "D*p", true },
	WildcardData { "Desktop", "Desktop*", true },
	WildcardData { "Desktop", "D**e**p", true }
));

INSTANTIATE_TEST_SUITE_P(PatternsNotMatching, WildcardTest, testing::Values(
	WildcardData { "Desktop", "p*", false },
	WildcardData { "Desktop", "*D", false },
	WildcardData { "Desktop", "*a", false },
	WildcardData { "Desktop", "Desk*ktop", false },
	WildcardData { "Desktop", "D*o*e*p", false },
	WildcardData { "Desktop", "*o*e*p", false }
));
