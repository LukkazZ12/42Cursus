/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 20:24:44 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void)
{
	char	type = 'A' + rand() % 3;
	Base	*base;

	std::cout << "Generated " << GREEN << type << RESET << " type class.\n";
	switch (type)
	{
		case 'A':
			base = new A();
			break ;
		case 'B':
			base = new B();
			break ;
		case 'C':
			base = new C();
			break ;
	}
	return (base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The actual type of the object is " << GREEN << "A.\n" << RESET;
	else if (dynamic_cast<B *>(p))
		std::cout << "The actual type of the object is " << GREEN << "B.\n" << RESET;
	else if (dynamic_cast<C *>(p))
		std::cout << "The actual type of the object is " << GREEN << "C.\n" << RESET;
	else
		std::cout << RED << "The actual type of the object is neither A, nor B, nor C.\n" << RESET;
}

void	identify(Base &p)
{
	try {
		A	a = dynamic_cast<A &>(p);
		std::cout << "The actual type of the object is " << GREEN << "A.\n" << RESET;
	}
	catch (...)
	{
		try
		{
			B	b = dynamic_cast<B &>(p);
			std::cout << "The actual type of the object is " << GREEN << "B.\n" << RESET;
		}
		catch (...)
		{
			try
			{
				C	c = dynamic_cast<C &>(p);
				std::cout << "The actual type of the object is " << GREEN << "C.\n" << RESET;
			}
			catch (...)
			{
				std::cout << RED << "The actual type of the object is neither A, nor B, nor C.\n" << RESET;
			}
		}
	}
}
