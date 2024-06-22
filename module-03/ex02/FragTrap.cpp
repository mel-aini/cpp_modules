/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:31 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/21 09:20:19 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& C) {
	*this = C;
}

FragTrap& FragTrap::operator= (const FragTrap& C) {
	this->name = C.getName();
	this->hitPoints = C.getHitPoints();
	this->energyPoints = C.getEnergyPoints();
	this->attackDamage = C.getAttackDamage();
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Default destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "High five guys" << std::endl;
}