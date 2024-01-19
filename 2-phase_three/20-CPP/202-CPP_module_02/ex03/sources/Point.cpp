/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/19 18:55:53 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	return ;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	return ;
}

Point::Point(const Point &point)
{
	*this = point;
	return ;
}

Point	&Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->x = point.getAbscissa();
		this->y = point.getOrdinate();
	}
	return (*this);
}

Point::~Point(void)
{
	return ;
}

Fixed	Point::getAbscissa(void) const
{
	return (this->x);
}

Fixed	Point::getOrdinate(void) const
{
	return (this->y);
}

void	Point::setCoordinates(const int x, const int y)
{
	this->x = x;
	this->y = y;
	return ;
}

Fixed	sideLen(Point const vertexA, Point const vertexB)
{
	Fixed	x0 = vertexA.getAbscissa();
	Fixed	x1 = vertexB.getAbscissa();
	Fixed	y0 = vertexA.getOrdinate();
	Fixed	y1 = vertexB.getOrdinate();

	float	len = sqrt(pow(Fixed(x1 - x0).toFloat(), 2) + pow(Fixed(y1 - y0).toFloat(), 2));
	return (len);
}
