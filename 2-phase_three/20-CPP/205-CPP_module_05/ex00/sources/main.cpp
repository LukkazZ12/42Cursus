/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 16:57:28 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Bureaucrat", 160);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat	bureaucrat("Bureaucrat", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	dumbestBureaucrat("byoshimo's coworker", 150);
	Bureaucrat	smartestBureaucrat("byoshimo", 1);

	std::cout << dumbestBureaucrat;
	std::cout << smartestBureaucrat;
	try
	{
		dumbestBureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		smartestBureaucrat.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	} 
	return (0);
}
