/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/18 20:03:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << BLUE <<
		"Default constructor called.\n" << RESET;
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << BLUE <<
		"Copy constructor called.\n" << RESET;
	*this = fixed;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << BLUE <<
		"Copy assignment operator called.\n" << RESET;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BLUE <<
		"Destructor called.\n" << RESET;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << BLUE <<
		"getRawBits member function called.\n" << RESET;
	return (this->value);
}

void	Fixed::setRawBits(const int raw)
{
	this->value = raw;
	return ;
}
