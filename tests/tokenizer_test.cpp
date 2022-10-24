#include "gtest/gtest.h"

int Factorial(int n)
{
	return n * 2;
}

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(Factorial(0), 1);
}
