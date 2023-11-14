#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Span.hpp"

#include <vector>
#include <deque>
#include <list>
#include <set>

TEST(Span_test, many_numbers) {

	Span	s(100000);

	// sの値を初期化
	s.addNumber(-10000, 20000);
	s.addNumber(10000);

	const int	expect_shortest_num = 1;
	const int	expect_longest_num = 10000;
	const int	actual_shortest_num = s.shortestSpan();
	const int	actual_longest_num = s.longestSpan();

	EXPECT_EQ(expect_shortest_num, actual_shortest_num);
	EXPECT_EQ(expect_longest_num, actual_longest_num);
}

TEST(Span_test, random_numbers) {

	Span	s(10);

	// sの値を初期化
	int	mul = 0
	for (size_t i = 0; i < 10; i++)
	{
		s.addNumber(i * mul);
		mul++;
	}

	const int	expect_shortest_num = 1;
	const int	expect_longest_num = (9 * 9) - (8 * 8);
	const int	actual_shortest_num = s.shortestSpan();
	const int	actual_longest_num = s.longestSpan();

	EXPECT_EQ(expect_shortest_num, actual_shortest_num);
	EXPECT_EQ(expect_longest_num, actual_longest_num);
}

TEST(Span_test, exeption_tooManyNum) {

	Span	s1(1);

	EXPECT_THROW(
		{
			s1.addNumber(1);
			s1.addNumber(2);
		},
		std::runtimeerror
	);

	Span	s2(0);

	EXPECT_THROW(
		{
			s2.addNumber(1);
		},
		std::runtimeerror
	);
}

TEST(Span_test, exeption_no_numbers_stored) {

	Span	s(100);

	EXPECT_THROW(
		{
			s.shortestSpan();
		},
		std::runtimeerror
	);

	EXPECT_THROW(
		{
			s.longestSpan();
		},
		std::runtimeerror
	);
}

TEST(Span_test, exeption_only_one_stored) {

	Span	s(100);

	EXPECT_THROW(
		{
			s.addNum(1);
			s.shortestSpan();
		},
		std::runtimeerror
	);

	EXPECT_THROW(
		{
			s.longestSpan();
		},
		std::runtimeerror
	);
}