#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& I) {
    *this = I;
}

Intern& Intern::operator= (const Intern& I) {
    (void)I;
	return *this;
}

AForm*  Intern::makeShrubbery(std::string formName, std::string formTarget) {
    AForm *form;
    try {
        form = new ShrubberyCreationForm(formTarget);
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return NULL;
}

AForm*  Intern::makeRobotomy(std::string formName, std::string formTarget) {
    AForm *form;
    try {
        form = new RobotomyRequestForm(formTarget);
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return NULL;
}

AForm*  Intern::makePresidential(std::string formName, std::string formTarget) {
    AForm *form;
    try {
        form = new PresidentialPardonForm(formTarget);
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return NULL;
}

AForm*  Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*ptrs[3])(std::string, std::string) = {
			&Intern::makeShrubbery, 
			&Intern::makeRobotomy, 
			&Intern::makePresidential
	};

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            return (this->*ptrs[i])(formName, formTarget);
        }
    }
    std::cout << "form <" << formName << "> doesn’t exist" << std::endl;
    return NULL;
}

Intern::~Intern() {}
