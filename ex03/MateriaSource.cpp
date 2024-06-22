/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:35:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/24 18:22:54 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	*this = obj;
	
}

MateriaSource& MateriaSource::operator = (const MateriaSource& obj) {
	std::cout << "MateriaSource copy assignement operator" << std::endl;
	if (this != &obj) {
		for (int i = 0; i < 4; i++) {
			this->materias[i] = obj.materias[i] ? obj.materias[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->materias[i];
	}
}

AMateria* MateriaSource::getMateria(const int index) const {
	if (index < 0 || index > 3) return NULL;
	return this->materias[index];
}

void	MateriaSource::learnMateria(AMateria* mat) {
	if (!mat) return;

	for (int i = 0; i < 4; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = mat->clone();
			break ;
		}
	}
	delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (type != "cure" && type != "ice") {
		std::cout << "unknown type" << std::endl;
		return 0;
	}

	for (int i = 3; i >= 0; i--) {
		if (this->materias[i] == NULL) continue;
		if (this->materias[i]->getType() == type) {
			return this->materias[i]->clone();
		}
	}
	return NULL;
}