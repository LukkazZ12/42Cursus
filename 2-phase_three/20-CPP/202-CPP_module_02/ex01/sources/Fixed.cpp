/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/18 20:04:06 by lucade-s         ###   ########.fr       */
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
		this->value = fixed.value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BLUE <<
		"Destructor called.\n" << RESET;
	return ;
}

Fixed::Fixed(const int number)
{
	std::cout << BLUE <<
		"Int constructor called.\n" << RESET;
	this->value = number << this->fractionalBits;
	return ;
}

Fixed::Fixed(const float number)
{
	std::cout << BLUE <<
		"Float constructor called.\n" << RESET;
	this->value = (int)roundf(number * pow(2, this->fractionalBits));
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

float	Fixed::toFloat(void) const
{
	return ((float)this->value / pow(2, this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->fractionalBits);
}

std::ostream	&operator<<(std::ostream &lhs, const Fixed &f)
{
	lhs << f.toFloat();
	return (lhs);
}
