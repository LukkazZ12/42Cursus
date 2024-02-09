/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/09 19:17:07 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << BLUE <<
		"Span default constructor called.\n" << RESET;
	this->size = 0;
	return ;
}

Span::Span(unsigned int N)
{
	std::cout << BLUE <<
		"Span int constructor called.\n" << RESET;
	this->size = N;
	return ;
}

Span::Span(const Span &span)
{
	std::cout << BLUE <<
		"Span copy constructor called.\n" << RESET;
	*this = span;
	return ;
}

Span	&Span::operator=(const Span &span)
{
	std::cout << BLUE <<
		"Span copy assignment operator called.\n" << RESET;
	if (this != &span)
	{
		this->size = span.size;
		for (unsigned int i = 0; i < span.integers.size(); i++)
			this->integers.push_back(span.integers[i]);
	}
	return (*this);
}

Span::~Span(void)
{
	std::cout << BLUE <<
		"Span default destructor called.\n" << RESET;
	return ;
}

unsigned int	Span::getSize(void) const
{
	return (this->size);
}

int	Span::getInteger(unsigned int i) const
{
	return (this->integers[i]);
}

void	Span::setInteger(unsigned int i, int integer)
{
	this->integers[i] = integer;
}

void	Span::addNumber(int number)
{
	if (!this->size)
		throw std::runtime_error("The integers vector size is 0.");
	if (this->integers.size() == this->size)
		throw std::runtime_error("The integers vector is already full.");
	else
		this->integers.push_back(number);
	return ;
}

int	Span::shortestSpan(void)
{
	if (!this->integers.size())
		throw std::runtime_error("The integers vector is empty. No span can be found.");
	if (this->integers.size() == 1)
		throw std::runtime_error("The integers vector has only one number. No span can be found.");

	int	span = std::abs(this->integers[0] - this->integers[1]);

	for (unsigned int i = 0; i < this->integers.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < this->integers.size(); j++)
		{
			if (std::abs(this->integers[i] - this->integers[j]) < span)
				span = std::abs(this->integers[i] - this->integers[j]);
		}
	}
	return (span);
}

int	Span::longestSpan(void)
{
	if (!this->integers.size())
		throw std::runtime_error("The integers vector is empty. No span can be found.");
	if (this->integers.size() == 1)
		throw std::runtime_error("The integers vector has only one number. No span can be found.");

	int	max = this->integers[0];
	int	min = this->integers[0];

	for (unsigned int i = 1; i < this->integers.size(); i++)
	{
		if (this->integers[i] < min)
			min = this->integers[i];
		else if (this->integers[i] > max)
			max = this->integers[i];
	}
	return (max - min);
}
