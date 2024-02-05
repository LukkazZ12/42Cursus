/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/05 11:35:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << YELLOW << "Test 1 (int array)\n\n" << RESET;
	int			arrayInt[6] = {0, 1, 2, 3, 4, 5};

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
	std::string	arrayStr[4] = {"lucade-s", "byoshimo", "gacalaza", "ada-cruz"};
	::iter(arrayStr, 4, ::swap);
	for (int i = 0; i < 4; i++)
	{
		std::cout << arrayStr[i];
		if (i < 3)
			std::cout << ", ";
		else
			std::cout << "\n\n";
	}
	return (0);
}
