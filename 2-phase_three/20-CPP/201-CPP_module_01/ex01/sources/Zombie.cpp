/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:06:31 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/15 18:01:29 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName)
{
	this->name = zombieName;
	std::cout << BLUE << "Created zombie " << this->name << std::endl << RESET;
	return ;
}

Zombie::Zombie(void)
{
	this->name = "Nemesis";
	std::cout << BLUE << "Created zombie " << this->name << std::endl << RESET;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << BLUE << "Destroed zombie " << this->name << std::endl << RESET;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << GREEN << std::endl << this->name << RESET
		<< ":  BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
