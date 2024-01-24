/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:58 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 18:17:16 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap (), ScavTrap(), FragTrap()
{
	this->name = "Who am I?";
	this->type = "DiamondTrap";
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = FragTrap::HIT_POINTS;
	this->energyPoints = ScavTrap::ENERGY_POINTS;
	this->attackDamage = FragTrap::ATTACK_DAMAGE;
	std::cout << GREEN
		<< "DiamondTrap default constructor called.\n" << RESET;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), \
	ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->name = name;
	this->type = "DiamondTrap";
	this->hitPoints = FragTrap::HIT_POINTS;
	this->energyPoints = ScavTrap::ENERGY_POINTS;
	this->attackDamage = FragTrap::ATTACK_DAMAGE;
	std::cout << GREEN
		<< "DiamondTrap constructor called.\n" << RESET;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap.getName()), \
	ScavTrap(diamondTrap.getName()), FragTrap(diamondTrap.getName())
{
	if (this != &diamondTrap)
		*this = diamondTrap;
	std::cout << GREEN
		<< "DiamondTrap copy constructor called.\n" << RESET;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->name = diamondTrap.name;
		ClapTrap::name = diamondTrap.getName();
		this->type = diamondTrap.getType();
		this->hitPoints = diamondTrap.getHitPoints();
		this->energyPoints = diamondTrap.getEnergyPoints();
		this->attackDamage = diamondTrap.getAttackDamage();
	}
	std::cout << GREEN
		<< "DiamondTrap copy assignment operator called.\n" << RESET;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GREEN
		<< "DiamondTrap destructor called.\n" << RESET;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << GREEN << this->name << RESET << std::endl;
	std::cout << "ClapTrap name: " << GREEN << this->getName() << RESET << std::endl << std::endl;
	return ;
}
