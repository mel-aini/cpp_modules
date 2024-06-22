/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:35 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/14 11:55:18 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: 	name("form"), 
		isSigned(false),
		gradeToSign(150),
		gradeToExec(150)
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw AForm::GradeTooHighException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& B) 
	:	name(B.getName()),
		isSigned(B.getIsSigned()),
		gradeToSign(B.getGradeToSign()),
		gradeToExec(B.getGradeToExec()) {}

AForm& AForm::operator= (const AForm& F) {
	if (this != &F) {
		this->setIsSigned(F.getIsSigned());
	}
	return *this;
}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) 
	:	name(name), 
		isSigned(false), 
		gradeToSign(gradeToSign),
		gradeToExec(gradeToExec) 
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw AForm::GradeTooHighException();
}

const	std::string& AForm::getName() const {
	return this->name;
}

const bool&	AForm::getIsSigned() const {
	return this->isSigned;
}

const	int& AForm::getGradeToSign() const {
	return this->gradeToSign;
}

const	int& AForm::getGradeToExec() const {
	return this->gradeToExec;
}

void	AForm::setIsSigned(bool status) {
	this->isSigned = status;
}

std::ostream& operator << (std::ostream& os, const AForm& AF) {
	const std::string status = AF.getIsSigned() ? "signed " : "not signed";
	os << AF.getName() << " is " << status;
	os << ", grade to execute " << AF.getGradeToExec();
	os << ", grade to sign " << AF.getGradeToSign();
	return os;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Too High Grade";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Too Low Grade";
}

const char	*AForm::executionFailedException::what() const throw() {
	return "Execution failed";
}

void AForm::beSigned(Bureaucrat& Br) {
	if (Br.getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false || executor.getGrade() > this->getGradeToExec()) {
		throw AForm::executionFailedException();
	}
	this->executeFormAction();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}