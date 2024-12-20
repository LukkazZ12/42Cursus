/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/28 17:44:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// AForm					aform;
	PresidentialPardonForm	presidential("Lucas");
	RobotomyRequestForm		robotomy("42");
	ShrubberyCreationForm	shrubbery("home");
	Bureaucrat				dumbestBureaucrat("byoshimo's coworker", 150);

	try
	{
		dumbestBureaucrat.signForm(presidential);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		dumbestBureaucrat.signForm(robotomy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		dumbestBureaucrat.signForm(shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << presidential;
	std::cout << robotomy;
	std::cout << shrubbery;
	try
	{
		presidential.execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy.execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery.execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	smartestBureaucrat("byoshimo", 1);

	try
	{
		smartestBureaucrat.signForm(presidential);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		smartestBureaucrat.signForm(robotomy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		smartestBureaucrat.signForm(shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << presidential;
	std::cout << robotomy;
	std::cout << shrubbery;
	try
	{
		presidential.execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy.execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery.execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	mediocreBureaucrat("lucade-s", 138);

	try
	{
		presidential.execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy.execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery.execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
