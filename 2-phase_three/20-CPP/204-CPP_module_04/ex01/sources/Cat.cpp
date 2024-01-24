/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 18:15:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
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
		this->type = cat.getType();
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
