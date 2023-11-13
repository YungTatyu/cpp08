
#include <iostream>
#include <vector>

int	main()
{
	std::vector<int>	v;
	v.reserve(100);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::cout << v.capacity() << "\n";
	v.erase(v.begin(), v.end());
	std::cout << v.capacity() << "\n";
	return 0;
}