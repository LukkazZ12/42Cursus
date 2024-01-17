/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:27:02 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:14:22 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie				*zombieHorde = new Zombie[N];
	std::string			zombieName;
	std::string			numberName;

	for (int i = 0; i < N; i++)
	{
		std::stringstream	number;
		number << i;
		numberName = number.str();
		zombieName = name + numberName;
		zombieHorde[i].setName(zombieName);
	}
	return (zombieHorde);
}
