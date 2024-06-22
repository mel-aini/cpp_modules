#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& P) {
	*this = P;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& S) {
	if (this != &S) {
		this->target = S.getTarget();
		this->setIsSigned(S.getIsSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 137, 145), target(target) {}

const std::string& ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void	ShrubberyCreationForm::executeFormAction() const {
	std::string name = target + "_shrubbery";
	std::ofstream out(name);

	if (out.is_open()) {
		out << "               ,@@@@@@@," << std::endl 
		<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl 
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl 
		<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl 
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl 
		<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl 
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl 
		<< "       |o|        | |         | |" << std::endl 
		<< "       |.|        | |         | |" << std::endl 
		<< "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		out.close();
	}
}