/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:28:26 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:39:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		// canonical form
		Ice();
		Ice(const Ice& obj);
		Ice& operator = (const Ice& obj);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif