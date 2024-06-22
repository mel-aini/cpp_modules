/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 14:55:58 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = obj.getType();
	this->brain = new Brain();
	this->brain->setIdeas(obj.brain->getIdeas());
}

Cat& Cat::operator = (const Cat& obj) {
	std::cout << "Cat copy assignement operator called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
		delete this->brain;
		this->brain = new Brain();
		this->brain->setIdeas(obj.brain->getIdeas());
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return this->brain;
}

void Cat::setBrain(Brain* brain) {
	delete this->brain;
	this->brain = brain;
}