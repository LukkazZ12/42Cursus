/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/28 16:48:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Form", 25, 5)
{
	std::cout << RED <<
		"PresidentialPardonForm default constructor called.\n" << RESET;
	this->target = "Default";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Form", 25, 5)
{
	std::cout << RED <<
		"PresidentialPardonForm constructor called.\n" << RESET;
	this->target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential) : AForm("Presidential Form", 25, 5)
{
	std::cout << RED <<
		"PresidentialPardonForm copy constructor called.\n" << RESET;
	*this = presidential;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential)
{
	std::cout << RED <<
		"PresidentialPardonForm copy assignment operator called.\n" << RESET;
	if (this != &presidential)
		this->target = presidential.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED <<
		"PresidentialPardonForm destructor called.\n" << RESET;
	return ;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->getIsSigned() || bureaucrat.getGrade() > this->getGradeExecute())
	{
		std::cout << GREEN << bureaucrat.getName() << RESET
			<< " couldn't execute " << GREEN << this->getName() << RESET
			<< ". ";
		if (!this->getIsSigned())
			throw(AForm::FormNotSigned());
		else if (bureaucrat.getGrade() > this->getGradeExecute())
			throw(AForm::GradeTooLowException());
	}
	bureaucrat.executeForm(*this);
	std::cout << GREEN << this->target << RESET
		<< " has been pardoned by Zaphod Beeblebrox.\n";
	return ;
}
