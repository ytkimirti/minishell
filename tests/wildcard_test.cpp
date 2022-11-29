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

struct WildcardMatchData
{
	std::string str;
	std::string pattern;
	bool expected;
};


std::ostream& operator<<(std::ostream& stream, const WildcardMatchData& data)
{
	std::string string_bool = data.expected ? "true" : "false";
	stream << YEL;
	stream << "string: " << data.str << ", ";
	stream << "pattern: " << data.pattern << ", ";
	stream << "expected: " << string_bool;
	stream << RST;
	
	return stream;
}


class WildcardMatcherTest : public testing::TestWithParam<WildcardMatchData> {
};

TEST_P(WildcardMatcherTest, PatternMatching)
{
	WildcardMatchData data = GetParam();
	ASSERT_EQ(check_match((char *)data.str.c_str(), (char *)data.pattern.c_str()),data.expected);
}




INSTANTIATE_TEST_SUITE_P(PatternsMatching, WildcardMatcherTest, testing::Values(
	WildcardMatchData { "Desktop", "*", true },
	WildcardMatchData { "Desktop", "*e*", true },
	WildcardMatchData { "Desktop", "*k*", true },
	WildcardMatchData { "Desktop", "*p", true },
	WildcardMatchData { "Desktop", "*e*p", true },
	WildcardMatchData { "Desktop", "D*p", true },
	WildcardMatchData { "Desktop", "Desktop*", true },
	WildcardMatchData { "Desktop", "D**e**p", true },
	WildcardMatchData { "test", "test", true }
));

INSTANTIATE_TEST_SUITE_P(PatternsNotMatching, WildcardMatcherTest, testing::Values(
	WildcardMatchData { "Desktop", "p*", false },
	WildcardMatchData { "Desktop", "*D", false },
	WildcardMatchData { "Desktop", "*a", false },
	WildcardMatchData { "Desktop", "Desk*ktop", false },
	WildcardMatchData { "Desktop", "D*o*e*p", false },
	WildcardMatchData { "Desktop", "*o*e*p", false },
	WildcardMatchData { "..", "*.c", false },
	WildcardMatchData { ".", "*.c", false },
	WildcardMatchData { "Desktop", "test", false }
));



struct WildcardData
{
	std::string source;
	std::string pattern;
	std::vector<std::string> list;
};


class WildcardDirectoryChecker: public testing::TestWithParam<WildcardData> {};

std::ostream& operator<<(std::ostream& stream, const WildcardData& data)
{
	
	stream << YEL;
	stream << "source: " << data.source << ", ";
	stream << "pattern: " << data.pattern << std::endl;
	stream << "dirs: " << std::endl;
	for (int i = 0; i < data.list.size(); i++){
		stream << "\t" << data.list.at(i);
	}
	stream << std::endl << "end of dirs ";
	stream << RST;
	
	return stream;
}


TEST_P(WildcardDirectoryChecker, DirectoryChecking)
{
	WildcardData data = GetParam();
	char **patterns = ft_split((char *) data.pattern.c_str(),'/');
	t_pvec *vect = search_nodes((char *) data.source.c_str(), patterns);
	// void **arr = vect->arr;
	// char **list = (char **)arr;
	// int i = 0;
	// while (list[i]){
	// 	printf("Address of %d: %p\n",i,list[i]);
	// 	std::string str(list[i]);
	// 	std::cout << i << " " << str << std::endl;
	// 	i++;
	// }
}


INSTANTIATE_TEST_SUITE_P(DirectoryChecking, WildcardDirectoryChecker, testing::Values(
	WildcardData { "/Users/emakas/Documents/42Cursus/minishell", "tests/*.cpp" },
	WildcardData { "/Users/emakas/Documents/42Cursus/minishell", "*/*.c" },
	WildcardData { "/Users/emakas/Documents/42Cursus/minishell", "src/built*/*.c" }
));
