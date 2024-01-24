/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:59 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << GREEN <<
		"Cat default constructor called.\n" << RESET;
	this->type = "Cat";
	return ;
}

Cat::Cat(const Cat &cat)
{
	std::cout << GREEN <<
		"Cat copy constructor called.\n" << RESET;
	*this = cat;
	return ;
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::cout << GREEN <<
		"Cat copy assignment operator called.\n" << RESET;
	if (this != &cat)
		this->type = cat.getType();
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << GREEN <<
		"Cat destructor called.\n" << RESET;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "Meow!\n" << RESET;
	return ;
}
