/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/25 16:35:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << BLUE <<
		"AAnimal default constructor called.\n" << RESET;
	this->type = "What aanimal am I?";
	return ;
}

AAnimal::AAnimal(const AAnimal &aanimal)
{
	std::cout << BLUE <<
		"AAnimal copy constructor called.\n" << RESET;
	*this = aanimal;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &aanimal)
{
	std::cout << BLUE <<
		"AAnimal copy assignment operator called.\n" << RESET;
	if (this != &aanimal)
		this->type = aanimal.getType();
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << BLUE <<
		"AAnimal destructor called.\n" << RESET;
	return ;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << BLUE << "What does the afox say?\n" << RESET;
	return ;
}
