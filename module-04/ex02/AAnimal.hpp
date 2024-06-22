/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:02:43 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:32:58 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal& obj);
		AAnimal& operator = (const AAnimal& obj);
		virtual ~AAnimal();
		
		const std::string& getType() const;
		void setType(std::string type);
		virtual void makeSound() const = 0;
};

#endif