/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:27:51 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 20:56:45 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponA)
{
	this->name = name;
	this->weaponA = &weaponA;
	std::cout << BLUE << "Created HumanA " << this->name << ".\n" << RESET;
	return ;
}

HumanA::HumanA(void)
{
	this->name = "Unnecessary";
	std::cout << BLUE << "Created HumanA " << this->name << ".\n" << RESET;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << BLUE << "Destroed HumanA " << this->name << ".\n" << RESET;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << std::endl << GREEN << this->name << RESET
		<< " attacks with their " << GREEN << this->weaponA->getType() << ".\n" << RESET;
}
