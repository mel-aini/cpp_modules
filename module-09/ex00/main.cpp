#include <iostream>
#include "BitcoinExchange.hpp"

using namespace std;

int main(int ac, char *av[])
{
	try {
		if (ac != 2)
			throw "Invalid number of arguments";

		BitcoinExchange btc;
		// btc.showDatabase();
		btc.exchange(av[1]);

	}
	catch (const char *e) {
		std::cout << "Error: " << e << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}