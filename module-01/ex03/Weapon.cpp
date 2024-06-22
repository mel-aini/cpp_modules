/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:56:27 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/15 11:55:49 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type(NULL) {}

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const {
	return this->type;
}

void	Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {}
