/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 16:32:26 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	FragTrap	frag("Frag");
	FragTrap	fragCopy(frag);
	FragTrap	fragTrap;

	clap.getStatus();
	trap.getStatus();
	frag.getStatus();
	fragCopy.getStatus();
	fragTrap.getStatus();
	fragTrap = frag;
	for (int i = 0; i < 4; i++)
	{
		frag.attack(fragTrap.getName());
		fragTrap.takeDamage(frag.getAttackDamage());
	}
	frag.getStatus();
	fragTrap.getStatus();
	fragTrap.attack(trap.getName());
	for(int j = 0; j < 45; j++)
		frag.beRepaired(1);
	frag.getStatus();
	frag.attack(clap.getName());
	frag.highFivesGuys();
}
