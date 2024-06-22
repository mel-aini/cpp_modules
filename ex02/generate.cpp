#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	try {
		std::srand(std::time(0));
		int random = std::rand() % 3;
		switch (random) {
			case 0:
				return new A();
			case 1:
				return new B();
			case 2:
				return new C();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return NULL;
}