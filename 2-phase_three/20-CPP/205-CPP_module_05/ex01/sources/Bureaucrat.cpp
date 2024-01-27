/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 16:51:38 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Boring bureaucrat")
{
	std::cout << BLUE <<
		"Bureaucrat default constructor called.\n" << RESET;
	this->grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << BLUE <<
		"Bureaucrat constructor called.\n" << RESET;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << BLUE <<
		"Bureaucrat copy constructor called.\n" << RESET;
	*this = bureaucrat;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << BLUE <<
		"Bureaucrat copy assignment operator called.\n" << RESET;
	if (this != &bureaucrat)
	{
		const_cast<std::string &>(this->name) = bureaucrat.getName();
		this->grade = bureaucrat.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BLUE <<
		"Bureaucrat destructor called.\n" << RESET;
	return ;
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return ;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << GREEN << this->getName() << RESET
			<< " couldn't sign " << GREEN << form.getName() << RESET
			<< " because it's already signed.\n";
		return ;
	}
	form.beSigned(*this);
	if (form.getIsSigned() == true)
		std::cout << GREEN << this->getName() << RESET
			<< " signed " << GREEN << form.getName() << RESET << ".\n";
	else
		std::cout << GREEN << this->getName() << RESET
			<< " couldn't sign " << GREEN << form.getName() << RESET
			<< " because the grade is too low.\n";
	return ;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!\n");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!\n");
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &bureaucrat)
{
	lhs << bureaucrat.getName() << ", bureaucrat grade "
		<< GREEN << bureaucrat.getGrade() << RESET << std::endl;
	return (lhs);
}
