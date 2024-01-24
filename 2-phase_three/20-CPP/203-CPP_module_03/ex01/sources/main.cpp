/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 16:54:40 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	ScavTrap	scav("Scav");
	ScavTrap	scavCopy(scav);
	ScavTrap	scavTrap;

	clap.getStatus();
	trap.getStatus();
	scav.getStatus();
	scavCopy.getStatus();
	scavTrap.getStatus();
	scavTrap = scav;
	for (int i = 0; i < 6; i++)
	{
		scav.attack(scavTrap.getName());
		scavTrap.takeDamage(scav.getAttackDamage());
	}
	scav.getStatus();
	scavTrap.getStatus();
	scavTrap.attack(trap.getName());
	for(int j = 0; j < 45; j++)
		scav.beRepaired(1);
	scav.getStatus();
	scav.attack(clap.getName());
	scav.guardGate();
}
