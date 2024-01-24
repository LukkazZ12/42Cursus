/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:37 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/23 19:28:02 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		const static int	HIT_POINTS = 100;
		const static int	ENERGY_POINTS = 100;
		const static int	ATTACK_DAMAGE = 30;
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator=(const FragTrap &fragTrap);
		~FragTrap(void);
		void	highFivesGuys(void);
};

#endif