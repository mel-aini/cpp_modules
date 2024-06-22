/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:03:30 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 18:25:23 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure& obj) {
	std::cout << "Cure copy constructor" << std::endl;
	*this = obj;
}

Cure& Cure::operator = (const Cure& obj) {
	std::cout << "Cure copy assignement operator" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure default destructor" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals ";
	std::cout << target.getName() << "’s wounds *" << std::endl;
}