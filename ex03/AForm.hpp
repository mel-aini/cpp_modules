/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:01:39 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:20:11 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Bureaucrat;

class AForm {
	private:
		const std::string			name;
		bool						isSigned;
		const int					gradeToSign;
		const int					gradeToExec;

	public:
		AForm();
		AForm(const AForm& C);
		AForm& operator= (const AForm& C);
		virtual ~AForm();

		AForm(const std::string name, const int gradeToSign, const int gradeToExec);

		const	std::string&	getName() const;
		const 	bool&			getIsSigned() const;
		const	int&			getGradeToSign() const;
		const	int&			getGradeToExec() const;
	
		void	setIsSigned(bool status);

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};

		class executionFailedException : public std::exception {
			public:
				const char * what() const throw();
		};
	
		void	beSigned(Bureaucrat& Br);

		void	execute(Bureaucrat const & executor) const;

		virtual void	executeFormAction() const = 0;
};

std::ostream& operator << (std::ostream& os, const AForm& AF);