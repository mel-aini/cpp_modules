#include <iostream>
#include "PmergeMe.hpp"


int main(int ac, char *av[]) {
	try {
		if (ac < 2)
			throw "Invalid number of arguments";

		PmergeMe pmerge;
		pmerge.sortVector(av);
		pmerge.sortDeque(av);
	}
	catch (const char *e) {
		std::cout << "Error: " << e << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}