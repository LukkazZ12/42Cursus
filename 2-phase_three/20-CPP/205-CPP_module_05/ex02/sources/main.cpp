/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 19:46:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// AForm	form;
	// ShrubberyCreationForm	shrubbery("home");
	// ShrubberyCreationForm	shrubberyCreation(shrubbery);
	// ShrubberyCreationForm	shrubberyCreation1 = shrubbery;

	// std::cout << shrubbery.getName() << std::endl;
	// std::cout << shrubbery.getIsSigned() << std::endl;
	// std::cout << shrubbery.getGradeSign() << std::endl;
	// std::cout << shrubbery.getGradeExecute() << std::endl;
	// std::cout << shrubbery.getTarget() << std::endl;
	// std::cout << std::endl;
	// std::cout << shrubberyCreation.getName() << std::endl;
	// std::cout << shrubberyCreation.getIsSigned() << std::endl;
	// std::cout << shrubberyCreation.getGradeSign() << std::endl;
	// std::cout << shrubberyCreation.getGradeExecute() << std::endl;
	// std::cout << shrubberyCreation.getTarget() << std::endl;
	// std::cout << std::endl;
	// std::cout << shrubberyCreation1.getName() << std::endl;
	// std::cout << shrubberyCreation1.getIsSigned() << std::endl;
	// std::cout << shrubberyCreation1.getGradeSign() << std::endl;
	// std::cout << shrubberyCreation1.getGradeExecute() << std::endl;
	// std::cout << shrubberyCreation1.getTarget() << std::endl;
	
	RobotomyRequestForm	robotomy("42 case");
	Bureaucrat			bureaucrat("byoshimo", 150);

	try
	{
		bureaucrat.signForm(robotomy);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	robotomy.execute(bureaucrat);
	// robotomy.execute(bureaucrat);
	// robotomy.execute(bureaucrat);
	// robotomy.execute(bureaucrat);
	return (0);
}
