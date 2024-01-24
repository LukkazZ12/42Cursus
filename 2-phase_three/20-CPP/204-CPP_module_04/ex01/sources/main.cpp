/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 18:18:29 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// const Animal	*MrLonely[10];

	// for (int i = 0; i < 10; i++)
	// {
	// 	if (i < 5)
	// 		MrLonely[i] = new Dog();
	// 	else
	// 		MrLonely[i] = new Cat();
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "Mr. Lonely animal " << i << " type: " << BLUE
	// 		<< MrLonely[i]->getType() << RESET << std::endl;
	// 	std::cout << "Mr. Lonely " << MrLonely[i]->getType() << " " << i << " type: ";
	// 	MrLonely[i]->makeSound();
	// }
	// for (int i = 0; i < 10; i ++)
	// 	delete (MrLonely[i]);

	Cat	cat;

	for (int i = 0; i < 100; i++)
		cat.setBrainIdea("I want Whiskas!", i);
	// for (int i = 0; i < 100; i++)
	// 	std::cout << cat.getBrainIdea(i) << std::endl;

	Cat	Tom = cat;
	std::cout << Tom.getType() << std::endl;
	// for (int i = 0; i < 100; i++)
	// 	Tom.setBrainIdea("I don't want Whiskas anymore!", i);
	for (int i = 0; i < 100; i++)
		std::cout << Tom.getBrainIdea(i) << std::endl;

	// Cat	MandaChuva(Tom);
	// for (int i = 0; i < 100; i++)
	// 	std::cout << MandaChuva.getBrainIdea(i) << std::endl;
	return (0);
}
