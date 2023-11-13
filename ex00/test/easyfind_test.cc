#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>
#include <set>


//シーケンスコンテナのテスト
TEST(easyfind_test, findTarget_vector) {

	const std::vector<int>	v = {1, 2, 300, 1000, -200, -3};

	for (int i = 0; i < v.size(); i++)
	{
		const int	target = v[i];
		const int	actual = easyfind(v, target);
		EXPECT_EQ(target, actual);
	}
}

TEST(easyfind_test, findTarget_deque) {

	const std::deque<int>	deque = {1, 2, 300, 1000, -200, -3};

	for (int i = 0; i < deque.size(); i++)
	{
		const int	target = deque[i];
		const int	actual = easyfind(deque, target);
		EXPECT_EQ(target, actual);
	}
}

TEST(easyfind_test, findTarget_list) {

	const std::list<int>	list = {1, 2, 300, 1000, -200, -3};

	for (auto it = list.begin(); it != list.end(); it++)
	{
		const int	target = *it;
		const int	actual = easyfind(list, target);
		EXPECT_EQ(target, actual);
	}
}

// 連想コンテナのテスト
TEST(easyfind_test, findTarget_set) {

	const std::set<int>	set = {1, 2, 300, 1000, -200, -3};

	for (auto it = set.begin(); it != set.end(); it++)
	{
		const int	target = *it;
		const int	actual = easyfind(set, target);
		EXPECT_EQ(target, actual);
	}
}

// 例外処理のテスト
TEST(easyfind_test, throwException) {

	const std::vector<int>	v = {1, 2, 300, 1000, -200, -3};

	for (int i = 0; i < v.size(); i++)
	{
		const int	target = v[i] - 100;
		EXPECT_THROW(
			{
				const int	actual = easyfind(v, target);
			},
			std::runtime_error
		);
	}
}