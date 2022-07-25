#ifndef ASSERT_H
#define ASSERT_EQUALS(expected, actual) assertEquals(expected, actual, #actual)

#include "intbst.h"


using namespace std;
void assertEquals(int expected, int actual, std::string message="");
#define ASSERT_TRUE(expression) assertTrue(expression, #expression)
void assertTrue(bool expression, std::string message="");
#endif