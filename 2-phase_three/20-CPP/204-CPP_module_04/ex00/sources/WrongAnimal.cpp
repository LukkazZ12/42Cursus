/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 16:35:10 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << BLUE <<
		"Wrong animal default constructor called.\n" << RESET;
	this->type = "What wrong animal am I?";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	std::cout << BLUE <<
		"Wrong animal copy constructor called.\n" << RESET;
	*this = wrongAnimal;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << BLUE <<
		"Wrong animal copy assignment operator called.\n" << RESET;
	if (this != &wrongAnimal)
		this->type = wrongAnimal.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << BLUE <<
		"Wrong animal destructor called.\n" << RESET;
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << BLUE << "What does the wrong fox say?\n" << RESET;
	return ;
}
