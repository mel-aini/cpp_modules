/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/09 13:59:21 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = obj.getType();
}

WrongCat& WrongCat::operator = (const WrongCat& obj) {
	std::cout << "WrongCat copy assignement called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "meow" << std::endl;
}