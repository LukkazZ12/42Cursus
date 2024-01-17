/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:19:48 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:17:48 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weaponB;
	public:
		HumanB(std::string name);
		HumanB(void);
		~HumanB(void);
		void		attack(void);
		void		setWeapon(Weapon &weaponB);
};

#endif