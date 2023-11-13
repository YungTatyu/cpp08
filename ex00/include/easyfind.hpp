#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>

template <typename T>
int&	easyfind(T& container, const int target)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == target)
			return *it;
	}
	throw std::runtime_error("target not found in the container");
};

template <typename T>
const int&	easyfind(const T& container, const int target)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == target)
			return *it;
	}
	throw std::runtime_error("target not found in the container");
};

#endif
