/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:04:25 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 15:11:21 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("default") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : type(obj.getType()) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& obj) {
	std::cout << "AAnimal copy assignement called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

const std::string& AAnimal::getType() const {
	return this->type;
}

void AAnimal::setType(std::string type) {
	this->type = type;
}
