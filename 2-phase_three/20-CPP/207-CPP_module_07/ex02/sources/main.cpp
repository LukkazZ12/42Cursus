/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/26 22:03:07 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(int, char**)
{
	Array<int>	a;
	Array<int>	b(0);

	try
	{
		a[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	try
	{
		b[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	std::cout << "a size: " << a.size() << std::endl;
	std::cout << "a address: " << a.getArray() << std::endl;
	std::cout << "b size: " << b.size() << std::endl;
	std::cout << "b address: " << b.getArray() << std::endl;
	
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int>	tmp = numbers;
	Array<int>	test(tmp);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i] || mirror[i] != tmp[i] || mirror[i] != test[i])
		{
			std::cerr << "Didn't save the same value!" << std::endl;
			return (1);
		}
	}
	mirror[250] = 1;
	numbers[250] = 2;
	tmp[250] = 3;
	test[250] = 4;
	std::cout << "mirror[250]: " << mirror[250] << '\n';
	std::cout << "numbers[250]: " << numbers[250] << '\n';
	std::cout << "tmp[250]: " << tmp[250] << '\n';
	std::cout << "test[250]: " << test[250] << '\n';
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	const Array<int>	zahlen = numbers;

	// zahlen[0] = 1;
	std::cout << "zahlen[0]: " << zahlen[0] << std::endl;
	return (0);
}
