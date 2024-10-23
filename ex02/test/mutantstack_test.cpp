#include "gtest/gtest-spi.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include "MutantStack.hpp"
#include <vector>

namespace test {
template <typename T>
void Setup(const std::vector<T> &v, MutantStack<T> &stack) {
  std::for_each(v.begin(), v.end(),
                [&stack](const T &value) { stack.push(value); });
}
} // namespace test

TEST(mutantstack_test, begin) {

  MutantStack<int> stack;
  test::Setup({1, 2, 3, 4, 5}, stack);
  MutantStack<int>::iterator it = stack.begin();

  EXPECT_EQ(*it, 1);
}

TEST(mutantstack_test, rbegin) {

  MutantStack<int> stack;
  test::Setup({1, 2, 3, 4, 5}, stack);
  MutantStack<int>::reverse_iterator it = stack.rbegin();

  EXPECT_EQ(*it, 5);
}
