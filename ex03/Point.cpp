/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:55:30 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 13:05:44 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Canonical Form

	// default constructor
	Point::Point() : x(Fixed(0)), y(Fixed(0)) {
		// std::cout << "Default constructor called" << std::endl;
	}

	// copy constructor
	Point::Point(const Point &obj) : x(obj.getX()), y(obj.getY()) {
		// std::cout << "Copy constructor called" << std::endl;
	}

	// copy assignement opeator
	Point& Point::operator = (const Point &f) {
		// std::cout << "Copy assignement operator called" << std::endl;
		(void)f;
		return *this;
	}

	// destructor
	Point::~Point() {
		// std::cout << "Destructor called" << std::endl;
	}

Point::Point(const float &f1, const float &f2) : x(Fixed(f1)), y(Fixed(f2)) {
	// std::cout << "param... constructor called" << std::endl;
}

Fixed Point::getX(void) const {
	return this->x;
}

Fixed Point::getY(void) const {
	return this->y;
}
