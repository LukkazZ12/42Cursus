/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/28 17:43:31 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	dumbestBureaucrat("byoshimo's coworker", 150);
	Intern		someRandomIntern;
	AForm		*form;
	AForm		*presidential;
	AForm		*robotomy;
	AForm		*shrubbery;

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	presidential = someRandomIntern.makeForm("PresidentialPardonForm", "Snider");
	robotomy = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	shrubbery = someRandomIntern.makeForm("ShrubberyCreationForm", "home");

	try
	{
		dumbestBureaucrat.signForm(*presidential);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		dumbestBureaucrat.signForm(*robotomy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		dumbestBureaucrat.signForm(*shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << *presidential;
	std::cout << *robotomy;
	std::cout << *shrubbery;
	try
	{
		presidential->execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy->execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery->execute(dumbestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	smartestBureaucrat("byoshimo", 1);

	try
	{
		smartestBureaucrat.signForm(*presidential);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		smartestBureaucrat.signForm(*robotomy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		smartestBureaucrat.signForm(*shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << *presidential;
	std::cout << *robotomy;
	std::cout << *shrubbery;
	try
	{
		presidential->execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy->execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery->execute(smartestBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	Bureaucrat	mediocreBureaucrat("lucade-s", 138);

	try
	{
		presidential->execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy->execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		robotomy->execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		shrubbery->execute(mediocreBureaucrat);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	delete (presidential);
	delete (robotomy);
	delete (shrubbery);
	return (0);
}
