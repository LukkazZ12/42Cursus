/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 16:41:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	ScavTrap	d;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.guardGate();
	b.attack("C");
	c.takeDamage(b.getAttackDamage());
	c.beRepaired(10);
	d.guardGate();

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
}
