/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:56:26 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/21 09:26:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& C);
		DiamondTrap& operator= (const DiamondTrap& C);
		~DiamondTrap();

		DiamondTrap(std::string name);
		
		void attack(const std::string& target);
		void whoAmI();
};

#endif