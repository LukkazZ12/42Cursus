/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 16:28:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << YELLOW <<
		"Brain default constructor called.\n" << RESET;
	return ;
}

Brain::Brain(const Brain &brain)
{
	std::cout << YELLOW <<
		"Brain copy constructor called.\n" << RESET;
	*this = brain;
	return ;
}

Brain	&Brain::operator=(const Brain &brain)
{
	std::cout << YELLOW <<
		"Brain copy assignment operator called.\n" << RESET;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << YELLOW <<
		"Brain destructor called.\n" << RESET;
	return ;
}
