/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 14:55:26 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = obj.getType();
	this->brain = new Brain();
	this->brain->setIdeas(obj.brain->getIdeas());
}

Dog& Dog::operator = (const Dog& obj) {
	std::cout << "Dog copy assignement operator called" << std::endl;
	if (this != &obj) {
		this->type = obj.getType();
		delete this->brain;
		this->brain = new Brain();
		this->brain->setIdeas(obj.brain->getIdeas());
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}

Brain* Dog::getBrain(void) const {
	return this->brain;
}

void Dog::setBrain(Brain* brain) {
	delete this->brain;
	this->brain = brain;
}