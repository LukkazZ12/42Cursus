/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/09 15:26:45 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	{
		std::cout << YELLOW << "Test 1 (size 0)\n\n" << RESET;
		Span	span;
		
		try
		{
			span.addNumber(6);
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		try
		{
			span.longestSpan();
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		std::cout << YELLOW << "\nTest 2 (size 1)\n\n" << RESET;
		Span	span(1);
		
		span.addNumber(6);
		std::cout << "Intergers vector: " << GREEN << span.getInteger(0) << "\n" << RESET;
		try
		{
			span.addNumber(0);
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		try
		{
			span.shortestSpan();
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		try
		{
			span.longestSpan();
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}
	{
		std::cout << YELLOW << "\nTest 3 (size > 1)\n\n" << RESET;
		Span	span(8);

		span.addNumber(5);
		span.addNumber(-7);
		span.addNumber(1658);
		span.addNumber(505);
		span.addNumber(-878);
		span.addNumber(36);
		span.addNumber(0);
		span.addNumber(9855);

		std::cout << "Intergers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << GREEN << span.getInteger(i) << RESET << (i < span.getSize() - 1 ? ", " : "\n");
		try
		{
			span.addNumber(0);
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		std::cout << "Shortest span: " << GREEN << span.shortestSpan() << "\n" << RESET;
		std::cout << "Longest span: " << GREEN << span.longestSpan() << "\n" << RESET;
	}
	{
		std::cout << YELLOW << "\nTest 4 (addNumbers)\n\n" << RESET;
		Span				span(10);
		std::vector<int>	vec;

		vec.push_back(5);
		vec.push_back(-7);
		vec.push_back(1658);
		vec.push_back(505);
		vec.push_back(-878);
		vec.push_back(36);
		vec.push_back(4);
		vec.push_back(9855);
		vec.push_back(139855);
		vec.push_back(-9445);
		vec.push_back(-37);

		std::cout << "Vector: ";
		for (unsigned int i = 0; i < vec.size(); i++)
			std::cout << GREEN << vec[i] << RESET << (i < vec.size() - 1 ? ", " : "\n");
		try
		{
			span.addNumbers(vec.begin(), vec.end());
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
		std::cout << "Intergers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << GREEN << span.getInteger(i) << RESET << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "Shortest span: " << GREEN << span.shortestSpan() << "\n" << RESET;
		std::cout << "Longest span: " << GREEN << span.longestSpan() << "\n" << RESET;
	}
	{
		std::cout << YELLOW << "\nTest 5 (copy)\n\n" << RESET;

		Span	span(3);

		span.addNumber(0);
		span.addNumber(1);
		span.addNumber(-100);
		
		Span	spanOpCopy = span;
		Span	spanCopy(span);

		std::cout << "Intergers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << GREEN << span.getInteger(i) << RESET << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "OpCopy Intergers vector: ";
		for (unsigned int i = 0; i < spanOpCopy.getSize(); i++)
			std::cout << GREEN << spanOpCopy.getInteger(i) << RESET << (i < spanOpCopy.getSize() - 1 ? ", " : "\n");
		std::cout << "Copy Intergers vector: ";
		for (unsigned int i = 0; i < spanCopy.getSize(); i++)
			std::cout << GREEN << spanCopy.getInteger(i) << RESET << (i < spanCopy.getSize() - 1 ? ", " : "\n");
		std::cout << YELLOW << "\nIs it a deep copy?\n" << RESET;
		span.setInteger(0, 15);
		spanOpCopy.setInteger(0, -200);
		spanCopy.setInteger(0, 9);
		std::cout << "Intergers vector: ";
		for (unsigned int i = 0; i < span.getSize(); i++)
			std::cout << GREEN << span.getInteger(i) << RESET << (i < span.getSize() - 1 ? ", " : "\n");
		std::cout << "OpCopy Intergers vector: ";
		for (unsigned int i = 0; i < spanOpCopy.getSize(); i++)
			std::cout << GREEN << spanOpCopy.getInteger(i) << RESET << (i < spanOpCopy.getSize() - 1 ? ", " : "\n");
		std::cout << "Copy Intergers vector: ";
		for (unsigned int i = 0; i < spanCopy.getSize(); i++)
			std::cout << GREEN << spanCopy.getInteger(i) << RESET << (i < spanCopy.getSize() - 1 ? ", " : "\n");
		std::cout << YELLOW << "\nShortest span:\n" << RESET;
		std::cout << "Span: " << GREEN << span.shortestSpan() << "\n" << RESET;
		std::cout << "SpanOpCopy: " << GREEN << spanOpCopy.shortestSpan() << "\n" << RESET;
		std::cout << "SpanCopy: " << GREEN << spanCopy.shortestSpan() << "\n" << RESET;
		std::cout << YELLOW << "\nLongest span:\n" << RESET;
		std::cout << "Span: " << GREEN << span.longestSpan() << "\n" << RESET;
		std::cout << "SpanOpCopy: " << GREEN << spanOpCopy.longestSpan() << "\n" << RESET;
		std::cout << "SpanCopy: " << GREEN << spanCopy.longestSpan() << "\n" << RESET;
	}
	return (0);
}
