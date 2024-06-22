/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:04:25 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:21:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.getType()) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& obj) {
	std::cout << "Animal copy assignement called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}


void Animal::makeSound() const {
	std::cout << "Animal makes sound" << std::endl;
}