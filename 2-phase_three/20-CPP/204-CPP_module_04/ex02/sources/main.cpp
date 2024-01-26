/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// const AAnimal	aanimal;
	const AAnimal	*MrLonely[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			MrLonely[i] = new Dog();
		else
			MrLonely[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Mr. Lonely animal " << i << " type: " << BLUE
			<< MrLonely[i]->getType() << RESET << std::endl;
		std::cout << "Mr. Lonely " << MrLonely[i]->getType()
			<< " " << i << " type: ";
		MrLonely[i]->makeSound();
	}
	for (int i = 0; i < 10; i ++)
		delete (MrLonely[i]);

	Cat	cat;

	std::cout << "cat type: " << BLUE
		<< cat.getType() << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		cat.setBrainIdea("I want Whiskas!", i);

	Cat	Tom = cat;
	
	std::cout << "Tom type: " << BLUE
		<< Tom.getType() << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << Tom.getBrainIdea(i) << std::endl;
	for (int i = 0; i < 100; i++)
		Tom.setBrainIdea("I don't want Whiskas anymore!", i);

	Cat	MandaChuva(Tom);
	std::cout << "Manda Chuva type: " << BLUE
		<< MandaChuva.getType() << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << MandaChuva.getBrainIdea(i) << std::endl;

	const AAnimal	*Garfield = new Cat();
	const AAnimal	*dog = new Dog();

	std::cout << "Garfield type: " << GREEN << Garfield->getType() << RESET << std::endl;
	std::cout << "dog type: " << RED << dog->getType() << RESET << std::endl;
	std::cout << "Garfield sound: ";
	Garfield->makeSound();
	std::cout << "dog sound: ";
	dog->makeSound();
	delete (Garfield);
	delete (dog);
	return (0);
}
