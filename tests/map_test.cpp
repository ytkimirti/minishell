#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <string>
extern "C" 
{
#include "hashing.h"
#include "utils.h"
#include "executer.h"
#include "token.h"
#include "tokenize_state.h"
#include "tokenizer.h"
#include "tokenizer_funcs.h"
#include "colors.h"
#include "map.h"
}
#include "gtest/gtest.h"
#include "test_utils.hpp"
#include "../libs/googletest/googletest/include/gtest/gtest.h"
#include <algorithm>

char	*random_str(int len)
{
	char *chars = (char *)"abcdefg";
	char *str = (char *)malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		str[i] = chars[rand() % (sizeof(chars) - 1)];
	}
	str[len] = '\0';

	return (str);
}

struct hash_and_str
{
	t_hash	hash;
	char	*str;
};

TEST(Map, HashingFunctions)
{
	GTEST_SKIP();
	srand(42);

	std::vector<hash_and_str> data;

	for (int i = 0; i < 100000; i++)
	{
		char *str = random_str(4);
		t_hash hash = hashcode_str(str);

		hash_and_str item;

		item.str = str;
		item.hash = hash;


		for (int i = 0; i < data.size(); i++)
		{
			if (data[i].hash == hash && strcmp(data[i].str, str) != 0)
			{
				// There is a hash collision
				printf("Hash collision between these\n\t\"%s\" -> %d\n\t\"%s\" -> %d\n", data[i].str, data[i].hash, str, hash);
				FAIL();
			}
		}
		data.push_back(item);
	}

	for (int i = 0; i < data.size(); i++)
	{
		free(data[i].str);
	}
}

TEST(Map, BasicStoring)
{
	t_map	*map;
	int		*a, *b, *c;

	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	c = (int *)malloc(sizeof(int));

	*a = 1;
	*b = 2;
	*c = 3;
	map = create_map(64);
	map_insert(map, hashcode_str("ahmet"), a);
	map_insert(map, hashcode_str("busra"), b);
	map_insert(map, hashcode_str("ceyda"), c);

	EXPECT_EQ(map_get(map, hashcode_str("ahmet")), a);
	EXPECT_EQ(map_get(map, hashcode_str("busra")), b);
	EXPECT_EQ(map_get(map, hashcode_str("ceyda")), c);
}

TEST(Map, UnknownItem)
{
	t_map	*map;
	int		*a, *b, *c;

	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	c = (int *)malloc(sizeof(int));

	*a = 1;
	*b = 2;
	*c = 3;
	map = create_map(64);
	map_insert(map, hashcode_str("ahmet"), a);
	map_insert(map, hashcode_str("busra"), b);
	map_insert(map, hashcode_str("ceyda"), c);

	EXPECT_EQ(map_get(map, hashcode_str("bwuuh")), nullptr);
	EXPECT_EQ(map_get(map, hashcode_str("busra")), b);
	EXPECT_EQ(map_get(map, hashcode_str("what")), nullptr);
}

TEST(Map, DeletionResultsNULL)
{
	t_map	*map;
	int		*a, *b, *c;

	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	c = (int *)malloc(sizeof(int));

	*a = 1;
	*b = 2;
	*c = 3;
	map = create_map(64);
	map_insert(map, hashcode_str("ahmet"), a);
	map_insert(map, hashcode_str("busra"), b);
	map_insert(map, hashcode_str("ceyda"), c);

	map_remove(map, hashcode_str("ahmet"), free);

	EXPECT_EQ(map_get(map, hashcode_str("ahmet")), nullptr);
	EXPECT_EQ(map_get(map, hashcode_str("busra")), b);
	EXPECT_EQ(map_get(map, hashcode_str("ceyda")), c);
}

void *global_pointer;

void debug_del(void *ptr)
{
	global_pointer = ptr;
}

TEST(Map, DeleteFunctionWorks)
{
	t_map	*map;
	int		*a, *b, *c;

	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	c = (int *)malloc(sizeof(int));

	*a = 1;
	*b = 2;
	*c = 3;
	map = create_map(64);
	map_insert(map, hashcode_str("ahmet"), a);
	map_insert(map, hashcode_str("busra"), b);
	map_insert(map, hashcode_str("ceyda"), c);

	global_pointer = nullptr;

	map_remove(map, hashcode_str("ahmet"), debug_del);

	EXPECT_EQ(global_pointer, a);

	free(global_pointer);

	EXPECT_EQ(map_get(map, hashcode_str("ahmet")), nullptr);
	EXPECT_EQ(map_get(map, hashcode_str("busra")), b);
	EXPECT_EQ(map_get(map, hashcode_str("ceyda")), c);
}
