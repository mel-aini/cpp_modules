/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:35 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/06 17:35:13 by mel-aini         ###   ########.fr       */
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
		// Canonical Form
		Fixed(); // default constructor
		Fixed(const Fixed &obj); // copy constructor
		Fixed& operator = (const Fixed &f); // copy assignement opeator
		~Fixed(); // destructor

		Fixed(const int value);
		Fixed(const float value);

		float toFloat( void ) const;
		int toInt( void ) const;


		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
};

std::ostream& operator << (std::ostream& os, const Fixed& obj); // << operator

#endif