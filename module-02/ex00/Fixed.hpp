/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:35 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 12:50:12 by mel-aini         ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator = (const Fixed &f);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif