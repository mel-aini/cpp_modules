/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:01:05 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 18:24:23 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice& obj) {
	std::cout << "Ice copy constructor" << std::endl;
	*this = obj;
}

Ice& Ice::operator = (const Ice& obj) {
	std::cout << "Ice copy assignement operator" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice default destructor" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}