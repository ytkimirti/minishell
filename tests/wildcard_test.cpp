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

TEST(Wildcard, CheckMatch1){
	if (check_match("Desktop", "*"))
	{
		printf("Congrats!\n");
	}
	else {
		FAIL();
	}
}
TEST(Wildcard, CheckMatch2)
{
	if (check_match("Desktop", "*"))
	{
		printf("Congrats!\n");
	}
	else
	{
		FAIL();
	}
}
TEST(Wildcard, CheckMatch3)
{
	if (check_match("Desktop", "*"))
	{
		printf("Congrats!\n");
	}
	else
	{
		FAIL();
	}
}
TEST(Wildcard, CheckMatch4)
{
	if (check_match("Desktop", "*"))
	{
		printf("Congrats!\n");
	}
	else
	{
		FAIL();
	}
}