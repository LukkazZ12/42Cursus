/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:19:51 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:13:27 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 7;
	Zombie	*Horde = zombieHorde(N, "Nemesis");

	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete[] Horde;
	return(0);
}
