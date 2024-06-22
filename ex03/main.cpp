#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	if (rrf)
		rrf->executeFormAction();
	
	delete rrf;
}