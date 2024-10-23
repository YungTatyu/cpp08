#include "gtest/gtest-spi.h"
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include "MutantStack.hpp"

#include <deque>
#include <list>
#include <set>
#include <vector>

TEST(mutantstack_test, begin) {

  MutantStack<int> stack = {1, 2, 3, 4, 5};
  MutantStack<int>::iterator it = stack.begin();

  EXPECT_EQ(*it, 1);
}

TEST(mutantstack_test, rbegin) {

  MutantStack<int> stack = {1, 2, 3, 4, 5};
  MutantStack<int>::iterator it = stack.rbegin();

  EXPECT_EQ(*it, 5);
}
