/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:50 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 17:10:30 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << MAGENTA
		<< "FragTrap default constructor called.\n" << RESET;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << MAGENTA <<
		"FragTrap constructor called.\n" << RESET;
	return ;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << MAGENTA
		<< "FragTrap copy constructor called.\n" << RESET;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << MAGENTA
		<< "FragTrap copy assignment operator called.\n" << RESET;
	if (this != &fragTrap)
	{
		this->name = fragTrap.getName();
		this->hitPoints = fragTrap.getHitPoints();
		this->energyPoints = fragTrap.getEnergyPoints();
		this->attackDamage = fragTrap.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << MAGENTA
		<< "FragTrap destructor called.\n" << RESET;
	return ;
}

void FragTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
		std::cout << "FragTrap " << GREEN << this->name << RESET
			<< " is dead and can't attack.\n";
	else if (!this->energyPoints)
		std::cout << "FragTrap " << GREEN << this->name << RESET
			<< " has no energy points to attack.\n";
	else
	{
		this->energyPoints--;
		std::cout << "FragTrap " << GREEN << this->name << RESET
			<< " attacks " << GREEN << target << RESET
			<< ", causing " << RED << this->attackDamage << RESET;
		if (this->attackDamage <= 1)
			std::cout << " point of damage!\n";
		else
			std::cout << " points of damage!\n";
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << GREEN << this->name << RESET
		<< " requested a high five!\n";
}
