/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:48:43 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 18:27:28 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) 
	: name(name)
{
	std::cout << "Character name constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
		this->matsLeft[i] = NULL;
	}
}

Character::Character() 
	: name("default")
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
		this->matsLeft[i] = NULL;
	}
}

Character::Character(const Character& C) {
	std::cout << "Character copy constructor" << std::endl;
	this->name = C.getName();
	for (int i = 0; i < 4; i++) {
		this->slots[i] = C.slots[i] ? C.slots[i]->clone() : NULL;
		this->matsLeft[i] = NULL;
	}
}

Character& Character::operator = (const Character& C) {
	std::cout << "Character copy assignement operator called" << std::endl;
	if (this != &C) {
		this->name = C.getName();
		for (int i = 0; i < 4; i++) {
			this->slots[i] = C.slots[i] ? C.slots[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character default destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->slots[i];
	}
	for (int i = 0; i < 4; i++) {
		bool alrDeleted = false;
		for (int j = 0; j < 4; j++)	{
			if (this->matsLeft[i] == this->slots[j]) {
				alrDeleted = true;
				break ;
			}
		}
		if (!alrDeleted)
			delete this->matsLeft[i];
	}
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) return;

	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == NULL) {
			this->saveMateria(m);
			this->slots[i] = m;
			break ;
		}
		if (m == this->slots[i]) {
			std::cout << "This Materia already equiped" << std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->slots[idx] == NULL) return;
	this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Bad Index, try to add from 0 to 3" << std::endl;
		return ;
	}
	if (this->slots[idx] == NULL) {
		std::cout << "Couldn't use that Materia" << std::endl;
		return ;
	}
	this->slots[idx]->use(target);
}

void	Character::clearFloor() {
	for (int i = 0; i < 4; i++) {
		delete matsLeft[i];
		matsLeft[i] = NULL;
	}
}

void	Character::saveMateria(AMateria *mat)
{
	if (mat == NULL) return;

	for (int i = 0; i < 4; i++) {
		if (this->matsLeft[i] == NULL) {
			this->matsLeft[i] = mat;
			return;
		}
	}
	this->clearFloor();
	this->matsLeft[0] = mat;
}