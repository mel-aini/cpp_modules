#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "type is A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "type is B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "type is C" << std::endl;
}

void identify(Base& p) {
	try {
        A& rA = dynamic_cast<A &>(p);
		(void)rA;
		std::cout << "type is A" << std::endl;
    }
    catch (std::exception& e) {}
	try {
        B& rB = dynamic_cast<B &>(p);
		(void)rB;
		std::cout << "type is B" << std::endl;
    }
    catch (std::exception& e) {}
	try {
        C& rC = dynamic_cast<C &>(p);
		(void)rC;
		std::cout << "type is C" << std::endl;
    }
    catch (std::exception& e) {}
}