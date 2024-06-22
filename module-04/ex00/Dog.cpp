/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:22:48 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = obj.getType();
}

Dog& Dog::operator = (const Dog& obj) {
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}