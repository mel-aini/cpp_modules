/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:36:16 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:35:30 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	 
	public:
		Dog();
		Dog(const Dog& obj);
		Dog& operator = (const Dog& obj);
		~Dog();

		void makeSound() const;

		Brain* getBrain(void) const;
		void setBrain(Brain* brain);
};

#endif