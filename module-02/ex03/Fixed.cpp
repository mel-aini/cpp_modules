/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:05:17 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 13:05:15 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits_nbr = 8;

// Canonical Form

	// default constructor
	Fixed::Fixed() : fixed_point(0) {
		// std::cout << "Default constructor called" << std::endl;
	}

	// copy constructor
	Fixed::Fixed(const Fixed &f) {
		// std::cout << "Copy constructor called" << std::endl;
		*this = f;
	}

	// copy assignement opeator
	Fixed& Fixed::operator = (const Fixed &f) {
		// std::cout << "Copy assignement operator called" << std::endl;
		this->fixed_point = f.getRawBits();
		return *this;
	}

	// destructor
	Fixed::~Fixed() {
		// std::cout << "Destructor called" << std::endl;
	}

// Int Constuctor
Fixed::Fixed(const int value) 
	: fixed_point(value << Fixed::fractional_bits_nbr) {
	// std::cout << "Int constructor called" << std::endl;
}

// Float Constuctor
Fixed::Fixed(const float value)
	: fixed_point(roundf(value * (1 << Fixed::fractional_bits_nbr))) {
	// std::cout << "Float constructor called" << std::endl;
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

// 6 comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator > (const Fixed& obj) {
	return (this->fixed_point > obj.getRawBits());
}

bool Fixed::operator < (const Fixed& obj) {
	return (this->fixed_point < obj.getRawBits());
}

bool Fixed::operator >= (const Fixed& obj) {
	return (this->fixed_point >= obj.getRawBits());
}

bool Fixed::operator <= (const Fixed& obj) {
	return (this->fixed_point <= obj.getRawBits());
}

bool Fixed::operator == (const Fixed& obj) {
	return (this->fixed_point == obj.getRawBits());
}

bool Fixed::operator != (const Fixed& obj) {
	return (this->fixed_point != obj.getRawBits());
}

// The 4 arithmetic operators: +, -, *, and /

Fixed Fixed::operator + (const Fixed& obj) {
	Fixed res;
	res.fixed_point = this->fixed_point + obj.getRawBits();
	return res;
}

Fixed Fixed::operator - (const Fixed& obj) {
	Fixed res;
	res.fixed_point = this->fixed_point - obj.getRawBits();
	return res;
}

Fixed Fixed::operator * (const Fixed& obj) {
	Fixed res;
	res.fixed_point = (this->fixed_point * obj.getRawBits()) >> Fixed::fractional_bits_nbr;
	return (res);
}

Fixed Fixed::operator / (const Fixed& obj) {
	Fixed res;
	res.fixed_point = (this->fixed_point << Fixed::fractional_bits_nbr) / obj.getRawBits();
	return res;
}

// The 4 increment/decrement

Fixed& Fixed::operator ++ ( void ) {
	this->fixed_point++;
	return *this;
}

Fixed Fixed::operator ++ ( int ) {
	Fixed tmp = *this;
	++this->fixed_point;
	return tmp;
}

Fixed& Fixed::operator -- ( void ) {
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator -- ( int ) {
	Fixed tmp = *this;
	--this->fixed_point;
	return tmp;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
	if (obj1.getRawBits() <= obj2.getRawBits())
		return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	if (obj1.getRawBits() <= obj2.getRawBits())
		return obj1;
	return obj2;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
	if (obj1.getRawBits() >= obj2.getRawBits())
		return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	if (obj1.getRawBits() >= obj2.getRawBits())
		return obj1;
	return obj2;
}

// Absolute
Fixed Fixed::absolute(const Fixed& obj) {
	if (obj.getRawBits() < 0)
		return (Fixed)obj * Fixed(-1);
	return obj;
}