/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/19 18:55:35 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed::Fixed(const int number)
{
	this->value = number << this->fractionalBits;
	return ;
}

Fixed::Fixed(const float number)
{
	this->value = (int)roundf(number * pow(2, this->fractionalBits));
	return ;
}

int	Fixed::getRawBits(void) const
{
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

std::ostream	&operator<<(std::ostream &lhs, const Fixed &fixed)
{
	lhs << fixed.toFloat();
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
	Fixed	fixed(*this);

	this->value++;
	return (fixed);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(*this);

	this->value--;
	return (fixed);
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
