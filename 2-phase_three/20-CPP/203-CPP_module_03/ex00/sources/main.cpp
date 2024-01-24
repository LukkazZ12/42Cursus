/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 16:08:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	ClapTrap	trapCopy(trap);
	ClapTrap	nameless;

	clap.getStatus();
	trap.getStatus();
	trapCopy.getStatus();
	nameless.getStatus();
	nameless = trap;
	clap.attack(nameless.getName());
	clap.getStatus();
	nameless.takeDamage(clap.getAttackDamage());
	nameless.beRepaired(1);
	nameless.getStatus();
}
