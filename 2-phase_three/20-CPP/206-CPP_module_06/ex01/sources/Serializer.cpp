/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 19:43:43 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << BLUE <<
		"Serializer default constructor called.\n" << RESET;
	return ;
}

Serializer::Serializer(const Serializer &serializer)
{
	std::cout << BLUE <<
		"Serializer copy constructor called.\n" << RESET;
	*this = serializer;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &serializer)
{
	std::cout << BLUE <<
		"Serializer copy assignment operator called.\n" << RESET;
	(void)serializer;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << BLUE <<
		"Serializer default destructor called.\n" << RESET;
	return ;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
