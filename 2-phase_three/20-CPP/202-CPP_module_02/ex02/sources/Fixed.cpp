/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/18 20:31:34 by lucade-s         ###   ########.fr       */
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

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	f(*this);

	this->value++;
	return (f);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f(*this);

	this->value--;
	return (f);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
