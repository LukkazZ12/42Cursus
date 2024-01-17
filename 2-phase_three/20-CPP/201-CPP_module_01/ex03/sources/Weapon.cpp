/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:07:16 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 19:31:07 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->type = weaponType;
	std::cout << BLUE << "Created " << this->type << ".\n" << RESET;
	return ;
}

Weapon::Weapon(void)
{
	this->type = "default weapon";
	std::cout << BLUE << "Created " << this->type << ".\n" << RESET;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << BLUE << "Destroed " << this->type << ".\n" << RESET;
	return ;
}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string weaponType)
{
	this->type = weaponType;
}
