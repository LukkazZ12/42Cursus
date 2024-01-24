/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:37 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 17:12:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		const static int	HIT_POINTS = 100;
		const static int	ENERGY_POINTS = 50;
		const static int	ATTACK_DAMAGE = 20;
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap &operator=(const ScavTrap &scavTrap);
		~ScavTrap(void);
		void	guardGate(void);
		void	attack(const std::string &target);
};

#endif