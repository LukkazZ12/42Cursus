/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 18:16:53 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamonds("Diamonds");
	DiamondTrap	shineBright("Shine Bright");
	DiamondTrap	lucy(diamonds);
	DiamondTrap	sky;

	diamonds.getStatus();
	shineBright.getStatus();
	lucy.getStatus();
	sky.getStatus();
	sky = shineBright;
	sky.getStatus();
	for (int i = 0; i < 4; i++)
	{
		sky.attack(diamonds.getName());
		diamonds.takeDamage(sky.getAttackDamage());
	}
	sky.getStatus();
	diamonds.getStatus();
	sky.whoAmI();
	shineBright.guardGate();
	lucy.highFivesGuys();
}
