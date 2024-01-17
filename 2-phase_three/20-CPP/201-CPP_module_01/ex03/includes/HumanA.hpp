/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:19:48 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:17:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		*weaponA;
	public:
		HumanA(std::string name, Weapon &weaponA);
		HumanA(void);
		~HumanA(void);
		void		attack(void);
};

#endif