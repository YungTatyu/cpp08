#include "gtest/gtest-spi.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include <iterator>
#include <string>
#include <vector>

#include "MutantStack.hpp"

namespace test {
template <typename T>
void Setup(const std::vector<T> &v, MutantStack<T> &stack) {
  std::for_each(v.begin(), v.end(),
                [&stack](const T &value) { stack.push(value); });
}

// 引数のstackはconstのほうがいいが、constのiteratorは実装していないので、参照にした
template <typename T>
void ExpectIteratorLoop(const std::vector<T> &expect, MutantStack<T> &stack) {
  std::size_t i = 0;
  std::for_each(stack.begin(), stack.end(), [&expect, &i](T &actual) {
    EXPECT_EQ(actual, expect[i]);
    ++i;
  });
}

template <typename T>
void ExpectRIteratorLoop(const std::vector<T> &expect, MutantStack<T> &stack) {
  std::vector<T> actual;
  for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
    actual.push_back(*it);
  }
  EXPECT_TRUE(actual == expect);
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

TEST(mutantstack_test, iterator_loop) {

  MutantStack<std::string> stack;
  const std::vector<std::string> v = {"this", "is", "test", "period"};
  test::Setup(v, stack);
  test::ExpectIteratorLoop(v, stack);
}

TEST(mutantstack_test, riterator_loop) {

  MutantStack<std::string> stack;
  const std::vector<std::string> v = {"this", "is", "test", "period"};
  const std::vector<std::string> expect(v.rbegin(), v.rend());
  test::Setup(v, stack);
  test::ExpectRIteratorLoop(expect, stack);
}
