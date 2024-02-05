/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/05 11:31:44 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int			a = 2;
	int			b = 3;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	float		e = 2.685;
	float		f = 3.9821;
	double		g = -0.9884;
	double		h = -0.9885;
	std::string	*i = NULL;
	std::string	*j = &c;

	std::cout << YELLOW << "Test 1 (int)\n\n" << RESET;
	std::cout << BLUE << "Before swap:\n" << RESET;
	std::cout << "a = " << GREEN << a << RESET << ", b = " << GREEN << b << RESET << std::endl;
	::swap(a, b);
	std::cout << BLUE << "\nAfter swap:\n" << RESET;
	std::cout << "a = " << GREEN << a << RESET << ", b = " << GREEN << b << RESET << std::endl;
	std::cout << "\nmin(a, b) = " << GREEN << ::min(a, b) << RESET << std::endl;
	std::cout << "max(a, b) = " << GREEN << ::max(a, b) << RESET << std::endl;

	std::cout << YELLOW << "\nTest 2 (string)\n\n" << RESET;
	std::cout << BLUE << "Before swap:\n" << RESET;
	std::cout << "c = " << GREEN << c << RESET << ", d = " << GREEN << d << RESET << std::endl;
	::swap(c, d);
	std::cout << BLUE << "\nAfter swap:\n" << RESET;
	std::cout << "c = " << GREEN << c << RESET << ", d = " << GREEN << d << RESET << std::endl;
	std::cout << "\nmin(c, d) = " << GREEN << ::min(c, d) << RESET << std::endl;
	std::cout << "max(c, d) = " << GREEN << ::max(c, d) << RESET << std::endl;

	std::cout << YELLOW << "\nTest 3 (float)\n\n" << RESET;
	std::cout << BLUE << "Before swap:\n" << RESET;
	std::cout << "e = " << GREEN << e << RESET << ", f = " << GREEN << f << RESET << std::endl;
	::swap(e, f);
	std::cout << BLUE << "\nAfter swap:\n" << RESET;
	std::cout << "e = " << GREEN << e << RESET << ", f = " << GREEN << f << RESET << std::endl;
	std::cout << "\nmin(e, f) = " << GREEN << ::min(e, f) << RESET << std::endl;
	std::cout << "max(e, f) = " << GREEN << ::max(e, f) << RESET << std::endl;

	std::cout << YELLOW << "\nTest 4 (double)\n\n" << RESET;
	std::cout << BLUE << "Before swap:\n" << RESET;
	std::cout << "g = " << GREEN << g << RESET << ", h = " << GREEN << h << RESET << std::endl;
	::swap(g, h);
	std::cout << BLUE << "\nAfter swap:\n" << RESET;
	std::cout << "g = " << GREEN << g << RESET << ", h = " << GREEN << h << RESET << std::endl;
	std::cout << "\nmin(g, h) = " << GREEN << ::min(g, h) << RESET << std::endl;
	std::cout << "max(g, h) = " << GREEN << ::max(g, h) << RESET << std::endl;

	std::cout << YELLOW << "\nTest 5 (pointer)\n\n" << RESET;
	std::cout << BLUE << "Before swap:\n" << RESET;
	std::cout << "i = " << GREEN << i << RESET << ", j = " << GREEN << j << RESET << std::endl;
	::swap(i, j);
	std::cout << BLUE << "\nAfter swap:\n" << RESET;
	std::cout << "i = " << GREEN << i << RESET << ", j = " << GREEN << j << RESET << std::endl;
	std::cout << "\nmin(i, j) = " << GREEN << ::min(i, j) << RESET << std::endl;
	std::cout << "max(i, j) = " << GREEN << ::max(i, j) << RESET << std::endl;
	return (0);
}
