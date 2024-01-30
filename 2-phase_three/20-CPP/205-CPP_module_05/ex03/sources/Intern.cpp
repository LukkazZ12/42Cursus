/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/28 17:29:50 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << CYAN <<
		"Intern default constructor called.\n" << RESET;
	return ;
}

Intern::Intern(const Intern &intern)
{
	std::cout << CYAN <<
		"Intern copy constructor called.\n" << RESET;
	*this = intern;
	return ;
}

Intern	&Intern::operator=(const Intern &intern)
{
	std::cout << CYAN <<
		"Intern copy assignment operator called.\n" << RESET;
	(void)intern;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << CYAN <<
		"Intern destructor called.\n" << RESET;
	return ;
}

static AForm	*makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	AForm		*(*f[])(std::string) = {makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm};
	std::string	validNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; ++i)
		if (name == validNames[i])
		{
			std::cout << "Intern creates " << GREEN << name << RESET << ".\n";
			return (f[i](target));
		}
	throw(Intern::FormNameNotExist());
}

const char	*Intern::FormNameNotExist::what(void) const throw()
{
	return ("The form name doesn't exist!\n");
}
