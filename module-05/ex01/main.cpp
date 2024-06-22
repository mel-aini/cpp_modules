/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:25:40 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 14:22:20 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		Bureaucrat b("Man", 5);

		Form	f("f1", 20, 20);

		b.signForm(f);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}