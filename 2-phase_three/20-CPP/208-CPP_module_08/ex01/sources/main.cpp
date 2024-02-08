/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/08 20:26:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main(void)
{
	// Span	span(2);
	// span.addNumber(0);
	// span.addNumber(1);
	
	// Span	oi = span;

	// std::cout << span.integers[0] << ", " << span.integers[1] << ", " << span.size << "\n";
	// std::cout << oi.integers[0] << ", " << oi.integers[1] << ", " << oi.size << "\n";
	// span.integers[0] = 2;
	// std::cout << span.integers[0] << ", " << span.integers[1] << ", " << span.size << "\n";
	// std::cout << oi.integers[0] << ", " << oi.integers[1] << ", " << oi.size << "\n";
	// try
	// {
	// 	span.shortestSpan();
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	Span	span(9);
	std::vector<int>	numbers;
	numbers.push_back(1);
	numbers.push_back(9);
	numbers.push_back(12);
	numbers.push_back(54);
	numbers.push_back(87);
	numbers.push_back(98);
	numbers.push_back(78);
	numbers.push_back(5);
	numbers.push_back(3);
	
	span.addNumbers(numbers.begin(), numbers.end());

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	return (0);
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
