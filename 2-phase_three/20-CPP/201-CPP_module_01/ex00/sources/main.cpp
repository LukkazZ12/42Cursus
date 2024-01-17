/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:19:51 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:11:27 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Lucas");
	Zombie	evilZombie;
	Zombie	*REZombie = newZombie("Resident Evil");

	randomChump("dos Palmares");
	zombie.announce();
	evilZombie.announce();
	REZombie->announce();
	delete(REZombie);
	return(0);
}
