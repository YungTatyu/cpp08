
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int	main()
{
	std::vector<int>	v;
	v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);

	// std::cout << &(easyfind(v, 2)) << '\n';
	// std::cout << &v[1] << '\n';
	// std::cout << &v[3] << "\n\n";

	// std::cout << &(easyfind(v, 5)) << '\n';
	// std::cout << &v[4] << '\n';
	// std::cout << &v[5] << '\n';

	return 0;
}