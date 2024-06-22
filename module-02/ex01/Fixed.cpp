/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:31:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 13:07:52 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits_nbr = 8;

// Canonical Form

	// default constructor
	Fixed::Fixed() : fixed_point(0) {
		std::cout << "Default constructor called" << std::endl;
	}

	// copy constructor
	Fixed::Fixed(const Fixed &f) {
		std::cout << "Copy constructor called" << std::endl;
		*this = f;
	}

	// copy assignement opeator
	Fixed& Fixed::operator = (const Fixed &f) {
		std::cout << "Copy assignement operator called" << std::endl;
		this->fixed_point = f.getRawBits();
		return *this;
	}

	// destructor
	Fixed::~Fixed() {
		std::cout << "Destructor called" << std::endl;
	}

// Int Constuctor
Fixed::Fixed(const int value) 
	: fixed_point(value << Fixed::fractional_bits_nbr) {
	std::cout << "Int constructor called" << std::endl;
}

// Float Constuctor
Fixed::Fixed(const float value)
	: fixed_point(roundf(value * (1 << Fixed::fractional_bits_nbr))) {
	std::cout << "Float constructor called" << std::endl;
}

// convert fixed point to float
float Fixed::toFloat( void ) const {
	return (float)this->fixed_point / (1 << Fixed::fractional_bits_nbr);
}

// convert fixed point to int
int Fixed::toInt( void ) const {
	return this->fixed_point >> Fixed::fractional_bits_nbr;
}

// << operator
std::ostream& operator << (std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

// Getter
int Fixed::getRawBits( void ) const {
	return this->fixed_point;
}

// Setter
void Fixed::setRawBits( int const raw ) {
	this->fixed_point = raw;
}