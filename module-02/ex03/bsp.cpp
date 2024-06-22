/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:53 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 11:07:43 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"



static Fixed calcArea(Point const a, Point const b, Point const c) {
	Fixed part1((Fixed)a.getX() * (Fixed)b.getY());
	Fixed part2((Fixed)b.getX() * (Fixed)c.getY());
	Fixed part3((Fixed)c.getX() * (Fixed)a.getY());

	Fixed SumA(part1 + part2 + part3);

	Fixed part4((Fixed)a.getY() * (Fixed)b.getX());
	Fixed part5((Fixed)b.getY() * (Fixed)c.getX());
	Fixed part6((Fixed)c.getY() * (Fixed)a.getX());

	Fixed SumB(part4 + part5 + part6);

	return Fixed(Fixed::absolute(SumA - SumB) / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed TArea(calcArea(a, b, c));

	Fixed subArea1(calcArea(point, b, c));
	Fixed subArea2(calcArea(a, point, c));
	Fixed subArea3(calcArea(a, b, point));

	Fixed subTotal(subArea1 + subArea2 + subArea3);

	// std::cout << "triangle area: " << TArea << std::endl;
	// std::cout << "sub area 1: " << subArea1 << std::endl;
	// std::cout << "sub area 2: " << subArea2 << std::endl;
	// std::cout << "sub area 3: " << subArea3 << std::endl;
	// std::cout << "total sub areas: " << subTotal << std::endl;

	if (TArea == subTotal) {
		if (subArea1 == Fixed(0) || subArea2 == Fixed(0) || subArea3 == Fixed(0)) {
			return false;
		}
		return true;
	}
	return false;
}
