/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:01:39 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:10:03 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Bureaucrat;

class Form {
	private:
		const std::string			name;
		bool						isSigned;
		const int					gradeToSign;
		const int					gradeToExec;

	public:
		Form();
		Form(const Form& F);
		Form& operator= (const Form& F);
		~Form();

		Form(const std::string name, const int gradeToSign, const int gradeToExec);

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

		void beSigned(Bureaucrat& Br);
};

std::ostream& operator << (std::ostream& os, const Form& F);