/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:52:50 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 13:09:20 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main() {

	{
		Point a(0, 0);
		Point b(0, 3);
		Point c(3, 0);

		Point p(1, 1);
		
		bool status = bsp(a, b, c, p);
		if (status)
			std::cout << "inside" << std::endl;
		else
			std::cout << "outside" << std::endl;
	}
	{
		Point a(1, 1);
		Point b(2, 4);
		Point c(5, 1);

		Point p(3, 3);
		bool status = bsp(a, b, c, p);
		if (status)
			std::cout << "inside" << std::endl;
		else
			std::cout << "outside" << std::endl;
	}

	return 0;
}
