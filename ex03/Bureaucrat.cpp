/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:54:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:16:05 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& B) : name(B.getName()), grade(B.getGrade()) {}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& B) {
	if (this != &B)
		this->grade = B.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

const	std::string& Bureaucrat::getName() const {
	return this->name;
}

const	int& Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exc: Too High Grade";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exc: Too Low Grade";
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& Br) {
	os << Br.getName() << " bureaucrat, his grade is " << Br.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm& F) {
	try {
		F.beSigned(*this);
		std::cout << this->getName() << " signed " << F.getName() << std::endl;
	}
	catch (std::exception &exc) {
		std::cout << this->getName() << " couldn’t sign " << F.getName();
		std::cout << " because " << exc.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
	}
	catch (std::exception &exc) {
		std::cerr << exc.what() << std::endl;
	}
}
