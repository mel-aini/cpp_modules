/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:18:49 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:12:25 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

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
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};

		void	signForm(AForm& F);

		void	executeForm(AForm const & form);
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& Br);
