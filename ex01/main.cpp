#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	try {
		Span sp = Span(1000000);
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);

		// sp.shortestSpan();
		std::vector<int> a;
		for (int i = 0; i < 1000000; i++) {
			a.push_back(i);
		}
		sp.addSequence(a.begin(), a.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const char *e) { std::cerr << e << std::endl; }
	return 0;
}