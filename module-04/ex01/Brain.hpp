/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:21:26 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/25 09:41:14 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator = (const Brain& obj);
		~Brain();

		Brain(const std::string* ideas);
		const std::string* getIdeas() const;
		void setIdeas(const std::string *ideas);
};

#endif