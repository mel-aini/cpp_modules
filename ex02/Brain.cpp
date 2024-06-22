/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:57:30 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 10:56:32 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator = (const Brain& obj) {
	std::cout << "Brain copy assignement operator called" << std::endl;
	if (this != &obj) {
		const std::string *oIdeas = obj.getIdeas();
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = oIdeas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const std::string* ideas) {
	for (int i = 0; i < 2; i++) {
		this->ideas[i] = ideas[i];
	}
}

const std::string* Brain::getIdeas() const {
	return this->ideas;
}

void Brain::setIdeas(const std::string *ideas) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}