/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 17:08:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	FragTrap	d("D");

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.attack("D");
	d.takeDamage(b.getAttackDamage());
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.attack("D");
	d.takeDamage(c.getAttackDamage());
	d.attack("C");
	c.takeDamage(d.getAttackDamage());
	d.highFivesGuys();
	b.beRepaired(1);
	c.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
}
