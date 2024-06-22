/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:35 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:19:10 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: 	name("Form"), 
		isSigned(false),
		gradeToSign(150),
		gradeToExec(150)
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& F)
	:	name(F.getName()),
		isSigned(F.getIsSigned()),
		gradeToSign(F.getGradeToSign()),
		gradeToExec(F.getGradeToExec()) {}

Form& Form::operator= (const Form& F) {
	if (this != &F)
		this->isSigned = F.getIsSigned();
	return *this;
}

Form::~Form() {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) 
	:	name(name), 
		isSigned(false), 
		gradeToSign(gradeToSign),
		gradeToExec(gradeToExec) 
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw Form::GradeTooHighException();
}

const	std::string& Form::getName() const {
	return this->name;
}

const bool&	Form::getIsSigned() const {
	return this->isSigned;
}

const	int& Form::getGradeToSign() const {
	return this->gradeToSign;
}

const	int& Form::getGradeToExec() const {
	return this->gradeToExec;
}

void	Form::setIsSigned(bool status) {
	this->isSigned = status;
}

std::ostream& operator << (std::ostream& os, const Form& F) {
	const std::string status = F.getIsSigned() ? "signed " : "not signed";
	os << F.getName() << " is " << status;
	os << ", grade to execute " << F.getGradeToExec();
	os << ", grade to sign " << F.getGradeToSign() << std::endl;
	return os;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Too High Grade";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Too Low Grade";
}

void Form::beSigned(Bureaucrat& Br) {
	if (Br.getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}