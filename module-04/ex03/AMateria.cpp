/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:38:11 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 18:28:16 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>


AMateria::AMateria() : type("default") {
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const AMateria& obj) {
	std::cout << "AMateria copy constructor" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator = (const AMateria& obj) {
	std::cout << "AMateria copy assignement operator" << std::endl;
	(void)obj;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria default destructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " use method from AMateria" << std::endl;
}
