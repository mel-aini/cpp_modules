/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:22:07 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = obj.getType();
}

Cat& Cat::operator = (const Cat& obj) {
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}