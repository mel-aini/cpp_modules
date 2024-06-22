#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	try {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

		int needle = easyfind(v, 2);
		std::cout << needle << std::endl;
	} catch (const char *e) {
		std::cout << e << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}