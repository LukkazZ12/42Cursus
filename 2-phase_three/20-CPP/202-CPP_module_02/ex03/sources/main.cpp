/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/19 16:32:11 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(2, 0);
	Point	c(0, 1);
	Point	point(0.5, 0.5);

	std::cout << YELLOW << "Length of the sides of the triangle:\na: " << sideLen(b, c) <<
		"\nb: " << sideLen(a, c) << "\nc: " << sideLen(a, b) << "\n\n";
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(0, 0);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(2, 0);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(0, 1);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(1, 0);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(1, 0.001);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(1, 0.01);
	message(a, b, c, point, bsp(a, b, c, point));
	point = Point(-5, 0);
	message(a, b, c, point, bsp(a, b, c, point));

	c = Point(1, 0);
	std::cout << YELLOW << "Length of the sides of the triangle:\na: " << sideLen(b, c) <<
		"\nb: " << sideLen(a, c) << "\nc: " << sideLen(a, b) << "\n\n";
	message(a, b, c, point, bsp(a, b, c, point));
	c = Point(2, 0);
	std::cout << YELLOW << "Length of the sides of the triangle:\na: " << sideLen(b, c) <<
		"\nb: " << sideLen(a, c) << "\nc: " << sideLen(a, b) << "\n\n";
	message(a, b, c, point, bsp(a, b, c, point));
	return (0);
}
