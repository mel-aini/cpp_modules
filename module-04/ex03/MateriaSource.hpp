/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:55 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:40:40 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator = (const MateriaSource& obj);
		~MateriaSource();

		AMateria* getMateria(const int index) const;

		void learnMateria(AMateria* mat);
		AMateria* createMateria(std::string const & type);
};

#endif