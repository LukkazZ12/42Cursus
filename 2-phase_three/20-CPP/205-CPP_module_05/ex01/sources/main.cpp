/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 19:41:33 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	form("42 case", 0, 50);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Form	form("42 case", 160, 50);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Form	form("42 case", 50, 160);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Form	form("42 case", 50, -160);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	dumbestBureaucrat("byoshimo's coworker", 150);
	Form		form("42 case", 50, 50);

	std::cout << dumbestBureaucrat;
	std::cout << form;
	try
	{
		dumbestBureaucrat.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
	Bureaucrat	smartestBureaucrat("byoshimo", 1);

	std::cout << smartestBureaucrat;
	try
	{
		smartestBureaucrat.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << smartestBureaucrat;
	std::cout << form;
	try
	{
		smartestBureaucrat.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << smartestBureaucrat;
	std::cout << form;
	try
	{
		smartestBureaucrat.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << smartestBureaucrat;
	std::cout << form;
	return (0);
}
