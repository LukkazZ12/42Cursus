/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:48:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 16:34:53 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "What's my name?";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << BLUE <<
		"Default constructor called.\n" << RESET;
	return ;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << BLUE <<
		"Name constructor called.\n" << RESET;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << BLUE <<
		"Copy constructor called.\n" << RESET;
	*this = clapTrap;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << BLUE <<
		"Copy assignment operator called.\n" << RESET;
	if (this != &clapTrap)
	{
		this->name = clapTrap.getName();
		this->hitPoints = clapTrap.getHitPoints();
		this->energyPoints = clapTrap.getEnergyPoints();
		this->attackDamage = clapTrap.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE <<
		"Destructor called.\n" << RESET;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " is dead and can't attack.\n";
	else if (!this->energyPoints)
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " has no energy points to attack.\n";
	else
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " attacks " << GREEN << target << RESET
			<< ", causing " << RED << this->attackDamage << RESET;
		if (this->attackDamage <= 1)
			std::cout << " point of damage!\n";
		else
			std::cout << " points of damage!\n";
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " is dead already.\n";
	else if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " took " << RED << this->hitPoints << RESET;
		if (this->hitPoints <= 1)
			std::cout << " point of damage and died.\n";
		else
			std::cout << " points of damage and died.\n";
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " took " << RED << amount << RESET
			<< " points of damage.\n";
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " is dead and can't be repaired.\n";
	else if (this->energyPoints == 0)
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " has no energy points to repair yourself.\n";
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << GREEN << this->name << RESET
			<< " was repaired, getting " << BLUE << amount << RESET
			<< " hit points back.\n";
	}
	return ;
}

void	ClapTrap::getStatus(void)
{
	std::cout << "ClapTrap " GREEN << this->name << RESET << " status:\n"
		<< "Hit points: " << this->hitPoints << std::endl
		<< "Energy points: " << this->energyPoints << std::endl
		<< "Attack damage: " << this->attackDamage << std::endl << std::endl;
}
