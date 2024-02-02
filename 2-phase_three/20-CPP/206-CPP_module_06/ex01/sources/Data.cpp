/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 20:57:15 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	std::cout << BLUE <<
		"Data default constructor called.\n" << RESET;
	this->value = 0;
	return ;
}

Data::Data(int value)
{
	std::cout << BLUE <<
		"Data int constructor called.\n" << RESET;
	this->value = value;
	return ;
}

Data::Data(const Data &data)
{
	std::cout << BLUE <<
		"Data copy constructor called.\n" << RESET;
	if (this != &data)
		*this = data;
	return ;
}

Data	&Data::operator=(const Data &data)
{
	std::cout << BLUE <<
		"Data copy assignment operator called.\n" << RESET;
	this->value = data.value;
	return (*this);
}

Data::~Data(void)
{
	std::cout << BLUE <<
		"Data default destructor called.\n" << RESET;
	return ;
}

int	Data::getValue(void) const
{
	return (this->value);
}

void	Data::setValue(int value)
{
	this->value = value;
}
