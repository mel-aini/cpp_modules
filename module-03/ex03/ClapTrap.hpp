/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:37:41 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/08 10:37:41 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& C);
		ClapTrap& operator= (const ClapTrap& C);
		~ClapTrap();

		ClapTrap(std::string name);
		
		const std::string& getName(void) const;
		const int& getHitPoints(void) const;
		const int& getEnergyPoints(void) const;
		const int& getAttackDamage(void) const;

		void setHitPoints(int points);
		void setEnergyPoints(int points);
		void setAttackDamage(int damage);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void log(void);
};

#endif