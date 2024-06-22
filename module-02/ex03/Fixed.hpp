/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:35 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 10:51:53 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					fixed_point;
		static const int	fractional_bits_nbr;
	
	public:
		// Canonical Form :
		Fixed(); // default constructor
		Fixed(const Fixed &obj); // copy constructor
		Fixed& operator = (const Fixed &f); // copy assignement opeator
		~Fixed(); // destructor

		Fixed(const int value);
		Fixed(const float value);

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator > (const Fixed& obj);
		bool operator < (const Fixed& obj);
		bool operator >= (const Fixed& obj);
		bool operator <= (const Fixed& obj);
		bool operator == (const Fixed& obj);
		bool operator != (const Fixed& obj);

		Fixed operator + (const Fixed& obj);
		Fixed operator - (const Fixed& obj);
		Fixed operator * (const Fixed& obj);
		Fixed operator / (const Fixed& obj);

		Fixed& operator ++ ( void );
		Fixed operator ++ ( int );
		Fixed& operator -- ( void );
		Fixed operator -- ( int );

		static Fixed absolute(const Fixed& obj);

		static Fixed& min(Fixed& obj1, Fixed& obj2);
		static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);
		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
};

std::ostream& operator << (std::ostream& os, const Fixed& obj); // << operator

#endif