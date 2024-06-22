#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat b("Man", 1);
		// b.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}