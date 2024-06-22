/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:30 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/15 12:48:51 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
}

void HumanB::attack() {
	if (this->weapon == NULL) {
		std::cout << this->name << " has no weapon" << std::endl;
	} else {
		std::cout << this->name;
		std::cout << " attacks with their ";
		std::cout << this->weapon->getType();
		std::cout << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}


HumanB::~HumanB() {}