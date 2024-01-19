/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/19 18:55:59 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point(void);
		Fixed	getAbscissa(void) const;
		Fixed	getOrdinate(void) const;
		void	setCoordinates(const int x, const int y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
void	message(Point const a, Point const b, Point const c, Point const point, bool is);
Fixed	sideLen(Point const vertexA, Point const vertexB);

#endif