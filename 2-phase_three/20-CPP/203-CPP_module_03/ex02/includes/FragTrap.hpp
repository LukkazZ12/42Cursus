/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:31:37 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/22 17:04:18 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator=(const FragTrap &fragTrap);
		~FragTrap(void);
		void	highFivesGuys(void);
		void	attack(const std::string &target);
};

#endif