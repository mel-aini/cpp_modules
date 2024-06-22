/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:40 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 14:21:04 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	try
	{
		Bureaucrat a("Man", 1);

		AForm	*f = new RobotomyRequestForm("target");

		a.signForm(*f);
		a.executeForm(*f);

		delete f;
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}