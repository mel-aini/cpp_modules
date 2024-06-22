/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:17:10 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:38:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria	*slots[4];
		AMateria	*matsLeft[4];

	public:
		// canonical form
		Character();
		Character(const Character& obj);
		Character& operator = (const Character& obj);
		~Character();

		Character(const std::string& name);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void clearFloor();
		void saveMateria(AMateria *mat);
};

#endif