/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 18:20:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << RED <<
		"Dog default constructor called.\n" << RESET;
	this->type = "Dog";
	this->brain = new Brain();
	return ;
}

Dog::Dog(const Dog &dog) : brain(new Brain(*dog.brain))
{
	std::cout << RED <<
		"Dog copy constructor called.\n" << RESET;
	*this = dog;
	return ;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << RED <<
		"Dog copy assignment operator called.\n" << RESET;
	if (this != &dog)
		this->type = dog.getType();
	return (*this);
}

Dog::~Dog(void)
{
	delete (this->brain);
	std::cout << RED <<
		"Dog destructor called.\n" << RESET;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << RED << "Woof-woof!\n" << RESET;
	return ;
}

std::string	Dog::getBrainIdea(int i) const
{
	return (this->brain->getIdea(i));
}

void	Dog::setBrainIdea(std::string idea, int i)
{
	this->brain->setIdea(idea, i);
}
