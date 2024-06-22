/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:55:32 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/18 13:05:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	
	public:
		// Canonical form
		Point();
		Point(const Point &obj);
		Point& operator = (const Point& P);
		~Point();

		Point(const float &f1, const float &f2);
	
		Fixed getX(void) const;
		Fixed getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif