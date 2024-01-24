/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/24 16:27:03 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*animal = new Animal();
	const Animal		*cat = new Cat();
	const Animal		*dog = new Dog();
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();
	const WrongCat		Tom;

	std::cout << "\nanimal type: " << BLUE << animal->getType() << RESET << std::endl;
	std::cout << "cat type: " << GREEN << cat->getType() << RESET << std::endl;
	std::cout << "dog type: " << RED << dog->getType() << RESET << std::endl;
	std::cout << "animal sound: ";
	animal->makeSound();
	std::cout << "cat sound: ";
	cat->makeSound();
	std::cout << "dog sound: ";
	dog->makeSound();

	std::cout << "\nwrongAnimal type: " << BLUE << wrongAnimal->getType() << RESET << std::endl;
	std::cout << "wrongCat type: " << GREEN << wrongCat->getType() << RESET << std::endl;
	std::cout << "Tom type: " << GREEN << Tom.getType() << RESET << std::endl;
	std::cout << "wrongAnimal sound: ";
	wrongAnimal->makeSound();
	std::cout << "wrongCat sound: ";
	wrongCat->makeSound();
	std::cout << "Tom sound: ";
	Tom.makeSound();
	std::cout << std::endl;

	delete(animal);
	delete(cat);
	delete(dog);
	delete(wrongAnimal);
	delete(wrongCat);
	return (0);
}
