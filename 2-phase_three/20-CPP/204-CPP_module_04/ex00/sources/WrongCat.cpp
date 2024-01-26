/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/26 15:15:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << GREEN <<
		"Wrong cat default constructor called.\n" << RESET;
	this->type = "Wrong cat";
	return ;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	std::cout << GREEN <<
		"Wrong cat copy constructor called.\n" << RESET;
	*this = wrongCat;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << GREEN <<
		"Wrong cat copy assignment operator called.\n" << RESET;
	if (this != &wrongCat)
		this->type = wrongCat.getType();
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << GREEN <<
		"Wrong cat destructor called.\n" << RESET;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << GREEN << "Wrong meow!\n" << RESET;
	return ;
}
