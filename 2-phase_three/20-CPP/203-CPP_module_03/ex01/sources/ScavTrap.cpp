/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:50 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 16:55:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << YELLOW
		<< "ScavTrap default constructor called.\n" << RESET;
	return ;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << YELLOW <<
		"ScavTrap constructor called.\n" << RESET;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << YELLOW
		<< "ScavTrap copy constructor called.\n" << RESET;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << YELLOW
		<< "ScavTrap copy assignment operator called.\n" << RESET;
	if (this != &scavTrap)
	{
		this->name = scavTrap.getName();
		this->hitPoints = scavTrap.getHitPoints();
		this->energyPoints = scavTrap.getEnergyPoints();
		this->attackDamage = scavTrap.getAttackDamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << YELLOW
		<< "ScavTrap destructor called.\n" << RESET;
	return ;
}

void ScavTrap::guardGate(void)
{
	std::cout << YELLOW
		<< "ScavTrap " << this->name << " is now in Gatekeeper mode.\n" << RESET;
	return ;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
		std::cout << "ScavTrap " << GREEN << this->name << RESET
			<< " is dead and can't attack.\n";
	else if (!this->energyPoints)
		std::cout << "ScavTrap " << GREEN << this->name << RESET
			<< " has no energy points to attack.\n";
	else
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << GREEN << this->name << RESET
			<< " attacks " << GREEN << target << RESET
			<< ", causing " << RED << this->attackDamage << RESET;
		if (this->attackDamage <= 1)
			std::cout << " point of damage!\n";
		else
			std::cout << " points of damage!\n";
	}
}
