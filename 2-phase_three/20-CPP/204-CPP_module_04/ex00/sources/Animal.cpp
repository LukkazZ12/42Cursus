/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:50 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << BLUE <<
		"Animal default constructor called.\n" << RESET;
	this->type = "What animal am I?";
	return ;
}

Animal::Animal(const Animal &animal)
{
	std::cout << BLUE <<
		"Animal copy constructor called.\n" << RESET;
	*this = animal;
	return ;
}

Animal	&Animal::operator=(const Animal &animal)
{
	std::cout << BLUE <<
		"Animal copy assignment operator called.\n" << RESET;
	if (this != &animal)
		this->type = animal.getType();
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << BLUE <<
		"Animal destructor called.\n" << RESET;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << BLUE << "What does the fox say?\n" << RESET;
	return ;
}
