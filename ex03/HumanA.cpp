/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:30 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/04 15:44:26 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack() {
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType();
	std::cout << std::endl;
}

HumanA::~HumanA() {}