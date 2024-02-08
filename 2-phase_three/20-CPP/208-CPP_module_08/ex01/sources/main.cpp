/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/07 16:04:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			arrayInt[6] = {0, 1, 2, 3, 4, 5};
	std::string	arrayStr[4] = {"lucade-s", "byoshimo", "gacalaza", "ada-cruz"};
	float		arrayFloat[3] = {2.685, -0.968, 15.9};
	double		arrayDouble[8] = {-10.9885, 0, 1.69, 8.9, 2.03, 12588.9, -100.2, -5687.12};

	std::cout << YELLOW << "Test 1 (int array)\n\n" << RESET;
	std::cout << BLUE << "Calling the inter function with swap function. Result:\n" << RESET;
	::iter(arrayInt, 6, ::swap);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arrayInt[i];
		if (i < 5)
			std::cout << ", ";
		else
			std::cout << "\n\n";
	}

	std::cout << YELLOW << "Test 2 (str array)\n\n" << RESET;
	std::cout << BLUE << "Calling the inter function with swap function. Result:\n" << RESET;
	::iter(arrayStr, 4, ::swap);
	for (int i = 0; i < 4; i++)
	{
		std::cout << arrayStr[i];
		if (i < 3)
			std::cout << ", ";
		else
			std::cout << "\n\n";
	}

	std::cout << YELLOW << "Test 3 (flost array)\n\n" << RESET;
	std::cout << BLUE << "Calling the inter function with swap function. Result:\n" << RESET;
	::iter(arrayFloat, 3, ::swap);
	for (int i = 0; i < 3; i++)
	{
		std::cout << arrayFloat[i];
		if (i < 2)
			std::cout << ", ";
		else
			std::cout << "\n\n";
	}

	std::cout << YELLOW << "Test 4 (double array)\n\n" << RESET;
	std::cout << BLUE << "Calling the inter function with swap function. Result:\n" << RESET;
	::iter(arrayDouble, 8, ::swap);
	for (int i = 0; i < 8; i++)
	{
		std::cout << arrayDouble[i];
		if (i < 7)
			std::cout << ", ";
		else
			std::cout << "\n\n";
	}
	return (0);
}
