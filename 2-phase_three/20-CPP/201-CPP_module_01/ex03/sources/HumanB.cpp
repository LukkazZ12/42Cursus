/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:40:16 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 20:56:45 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << BLUE << "Created HumanB " << this->name << ".\n" << RESET;
	return ;
}

HumanB::HumanB(void)
{
	this->name = "Violence";
	std::cout << BLUE << "Created HumanB " << this->name << ".\n" << RESET;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << BLUE << "Destroed HumanB " << this->name << ".\n" << RESET;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << std::endl << GREEN << this->name << RESET
		<< " attacks with their " << GREEN << this->weaponB->getType() << ".\n" << RESET;
}

void	HumanB::setWeapon(Weapon &weaponB)
{
	this->weaponB = &weaponB;
}
