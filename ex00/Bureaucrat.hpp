/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:18:49 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:09:35 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& B);
		Bureaucrat& operator= (const Bureaucrat& B);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);
		
		const	std::string& getName() const;
		const	int& getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& Br);
