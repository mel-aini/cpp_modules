/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:14:56 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& P) {
	*this = P;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& P) {
	if (this != &P) {
		this->target = P.getTarget();
		this->setIsSigned(P.getIsSigned());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 5, 25), target(target) {}

const std::string& PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::executeFormAction() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}