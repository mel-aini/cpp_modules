/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:58:38 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/04 17:22:54 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
		~HumanB();
	
};

#endif