/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:50 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 19:27:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->type = "FragTrap";
	this->hitPoints = this->HIT_POINTS;
	this->energyPoints = this->ENERGY_POINTS;
	this->attackDamage = this->ATTACK_DAMAGE;
	std::cout << MAGENTA
		<< "FragTrap default constructor called.\n" << RESET;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->type = "FragTrap";
	this->hitPoints = this->HIT_POINTS;
	this->energyPoints = this->ENERGY_POINTS;
	this->attackDamage = this->ATTACK_DAMAGE;
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
		this->type = fragTrap.getType();
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << GREEN << this->name << RESET
		<< " requested a high five!\n";
}
