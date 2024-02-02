/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/02 11:09:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	std::cout << YELLOW << "TEST 1\n" << RESET;

	Base	*ptrA = new A();
	Base	&refA = *ptrA;
	std::cout << "Generated " << GREEN << "A" << RESET << " type class.\n";
	Base	*ptrB = new B();
	Base	&refB = *ptrB;
	std::cout << "Generated " << GREEN << "B" << RESET << " type class.\n";
	Base	*ptrC = new C();
	Base	&refC = *ptrC;
	std::cout << "Generated " << GREEN << "C" << RESET << " type class.\n\n";

	std::cout << BLUE << "Identify pointers:\n" << RESET;
	identify(ptrA);
	identify(ptrB);
	identify(ptrC);
	std::cout << std::endl;

	std::cout << BLUE << "Identify references:\n" << RESET;
	identify(refA);
	identify(refB);
	identify(refC);

	delete ptrA;
	delete ptrB;
	delete ptrC;
	std::cout << std::endl;

	std::cout << YELLOW << "TEST 2 (RANDOM)\n" << RESET;

	Base	*ptr = generate();

	std::cout << BLUE << "Identify pointer:\n" << RESET;
	identify(ptr);

	std::cout << std::endl;

	std::cout << BLUE << "Identify reference:\n" << RESET;
	Base	&ref = *ptr;
	identify(ref);

	delete ptr;
	std::cout << std::endl;

	std::cout << YELLOW << "TEST 3 (CLASS D)\n" << RESET;

	Base	*ptrD = new D();
	Base	&refD = *ptrD;
	std::cout << "Generated " << GREEN << "D" << RESET << " type class.\n\n";

	std::cout << BLUE << "Identify pointer:\n" << RESET;
	identify(ptrD);

	std::cout << std::endl;

	std::cout << BLUE << "Identify reference:\n" << RESET;
	identify(refD);

	delete(ptrD);
	std::cout << std::endl;

	std::cout << YELLOW << "TEST 4 (INVALID POINTER)\n" << RESET;

	Base	*ptrNull = NULL;
	std::cout << "Generated a " << GREEN << "NULL" << RESET << " pointer.\n\n";

	std::cout << BLUE << "Identify pointer:\n" << RESET;
	identify(ptrNull);
	
	return (0);
}

