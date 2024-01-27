/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 19:42:00 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Form", 72, 45)
{
	std::cout << MAGENTA <<
		"RobotomyRequestForm default constructor called.\n" << RESET;
	this->target = "Default";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Form", 72, 45)
{
	std::cout << MAGENTA <<
		"RobotomyRequestForm constructor called.\n" << RESET;
	this->target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy) : AForm("Robotomy Form", 72, 45)
{
	std::cout << MAGENTA <<
		"RobotomyRequestForm copy constructor called.\n" << RESET;
	*this = robotomy;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	std::cout << MAGENTA <<
		"RobotomyRequestForm copy assignment operator called.\n" << RESET;
	if (this != &robotomy)
		this->target = robotomy.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA <<
		"RobotomyRequestForm destructor called.\n" << RESET;
	return ;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->getIsSigned())
		throw(AForm::FormNotSigned());
	else if (bureaucrat.getGrade() > this->getGradeExecute())
		throw(AForm::GradeTooLowException());
	bureaucrat.executeForm(*this);
	std::cout << RED << "O: DRILLING NOISES :O\n" << RESET;
	
	int	randomNumber = std::rand() % 100 + 1;

	if (randomNumber % 2 == 0)
		std::cout << GREEN << this->target << RESET << " has been robotomized.\n";
	else
		std::cout << RED << "The robotomy failed.\n" << RESET;
	return ;
}
