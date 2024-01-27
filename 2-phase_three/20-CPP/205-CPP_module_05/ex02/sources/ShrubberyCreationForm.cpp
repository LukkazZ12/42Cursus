/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 19:06:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Form", 145, 137)
{
	std::cout << GREEN <<
		"ShrubberyCreationForm default constructor called.\n" << RESET;
	this->target = "Default";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137)
{
	std::cout << GREEN <<
		"ShrubberyCreationForm constructor called.\n" << RESET;
	this->target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery) : AForm("Shrubbery Form", 145, 137)
{
	std::cout << GREEN <<
		"ShrubberyCreationForm copy constructor called.\n" << RESET;
	*this = shrubbery;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubbery)
{
	std::cout << GREEN <<
		"ShrubberyCreationForm copy assignment operator called.\n" << RESET;
	if (this != &shrubbery)
		this->target = shrubbery.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << GREEN <<
		"ShrubberyCreationForm destructor called.\n" << RESET;
	return ;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	std::string		filename = this->target + "_shrubbery";

	if (!this->getIsSigned())
		throw(AForm::FormNotSigned());
	else if (bureaucrat.getGrade() > this->getGradeExecute())
		throw(AForm::GradeTooLowException());
	bureaucrat.executeForm(*this);

	std::ofstream	file(filename.c_str());
	file << "   *\n";
	file << "  ***\n";
	file << " *****\n";
	file << "*******\n";
	file << "  ***\n";
	file << "  ***\n";
	file.close();
	return ;
}
