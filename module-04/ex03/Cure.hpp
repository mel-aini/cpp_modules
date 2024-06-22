/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:30:32 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:39:14 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		// canonical form
		Cure();
		Cure(const Cure& obj);
		Cure& operator = (const Cure& obj);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif