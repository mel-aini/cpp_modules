/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:31 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/21 09:13:40 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& C) {
	*this = C;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& C) {
	this->name = C.getName();
	this->hitPoints = C.getHitPoints();
	this->energyPoints = C.getEnergyPoints();
	this->attackDamage = C.getAttackDamage();
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) return;
	this->setEnergyPoints(this->energyPoints - 1);
	std::cout << "ScavTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << " causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name;
	std::cout << " is now in Gate keeper mode" << std::endl;
}