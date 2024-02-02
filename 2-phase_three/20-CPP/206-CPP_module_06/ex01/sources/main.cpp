/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 20:59:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	std::cout << YELLOW << "TEST 1\n" << RESET;
	Data		*ptr0 = new Data(42);
	Data		*deserializePtr0;
	uintptr_t	uintPtr0;

	uintPtr0 = Serializer::serialize(ptr0);
	deserializePtr0 = Serializer::deserialize(uintPtr0);

	std::cout << "Data's value through Data original pointer:\t"
		<< GREEN << ptr0->getValue() << RESET << std::endl;
	std::cout << "Data's value through Data deserialized pointer:\t"
		<< GREEN << deserializePtr0->getValue() << RESET << std::endl;
	delete (ptr0);
	std::cout << std::endl;
	
	std::cout << YELLOW << "TEST 2 (RANDOM)\n" << RESET;
	srand(time(NULL));
	Data		*ptr1 = new Data(std::rand() % 1000);
	uintptr_t	uintPtr1;
	Data		*deserializePtr1;

	uintPtr1 = Serializer::serialize(ptr1);
	deserializePtr1 = Serializer::deserialize(uintPtr1);

	std::cout << "Data's value through Data original pointer:\t"
		<< GREEN << ptr1->getValue() << RESET << std::endl;
	std::cout << "Data's value through Data deserialized pointer:\t"
		<< GREEN << deserializePtr1->getValue() << RESET << std::endl;
	delete (ptr1);
	std::cout << std::endl;

	std::cout << YELLOW << "TEST 3 (INVALID POINTER)\n" << RESET;
	Data		*ptr2 = NULL;
	std::cout << BLUE << "Created a Data object NULL.\n" << RESET;
	uintptr_t	uintPtr2;
	Data		*deserializePtr2;

	uintPtr2 = Serializer::serialize(ptr2);
	deserializePtr2 = Serializer::deserialize(uintPtr2);

	if (deserializePtr2 == NULL)
		std::cout << GREEN << "Deserialized pointer is NULL.\n" << RESET;
	else
		std::cout << RED << "Deserialized pointer is not NULL.\n" << RESET;
	return (0);
}
