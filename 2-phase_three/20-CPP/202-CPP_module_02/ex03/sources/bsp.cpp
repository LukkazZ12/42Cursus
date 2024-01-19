/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:18:45 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/19 19:53:51 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed x = point.getAbscissa();
	Fixed y = point.getOrdinate();

	Fixed x1 = a.getAbscissa();
	Fixed y1 = a.getOrdinate();
	Fixed x2 = b.getAbscissa();
	Fixed y2 = b.getOrdinate();
	Fixed x3 = c.getAbscissa();
	Fixed y3 = c.getOrdinate();

	Fixed detT = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
	Fixed alpha = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / detT;
	Fixed beta = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / detT;
	Fixed gamma = Fixed(1) - alpha - beta;

	return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0));
}

void	message(Point const a, Point const b, Point const c, Point const point, bool is)
{
	if (sideLen(a, b) >= sideLen(a, c) + sideLen(b, c) ||
		sideLen(b, c) >= sideLen(a, b) + sideLen(a, c) ||
		sideLen(a, c) >= sideLen(a, b) + sideLen(b, c))
	{
		std::cout << RED << "This is not a triangle.\n" << RESET;
		return ;
	}
	if (is)
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << "The point (" << point.getAbscissa() << ", " << point.getOrdinate() << ") is ";
	if (!is)
		std::cout << "not ";
	std::cout << "inside of the triangle of vertices ("
		<< a.getAbscissa() << ", " << a.getOrdinate() << "), ("
		<< b.getAbscissa() << ", " << b.getOrdinate() << ") and ("
		<< c.getAbscissa() << ", " << c.getOrdinate() << ").\n" << RESET;
	return ;
}
