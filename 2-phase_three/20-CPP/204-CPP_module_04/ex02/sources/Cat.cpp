/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/26 15:16:14 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << GREEN <<
		"Cat default constructor called.\n" << RESET;
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}

Cat::Cat(const Cat &cat) : brain(new Brain(*cat.brain))
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
	{
		this->type = cat.getType();
		*this->brain = *cat.brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete (this->brain);
	std::cout << GREEN <<
		"Cat destructor called.\n" << RESET;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << GREEN << "Meow!\n" << RESET;
	return ;
}

std::string	Cat::getBrainIdea(int i) const
{
	return (this->brain->getIdea(i));
}

void	Cat::setBrainIdea(std::string idea, int i)
{
	this->brain->setIdea(idea, i);
}
