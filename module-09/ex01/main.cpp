#include <iostream>
#include "RPN.hpp"

int main(int ac, char *av[]) {

	try {

		if (ac != 2)
			throw "Invalid number of arguments";

		RPN rpn;
		rpn.calculate(av[1]);
	}
	catch (const char *e) {
		std::cout << "Error: " << e << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}