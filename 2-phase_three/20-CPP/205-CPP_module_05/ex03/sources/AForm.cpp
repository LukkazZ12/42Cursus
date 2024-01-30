/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/28 16:39:06 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("Boring aform"), isSigned(false), \
	gradeSign(150), gradeExecute(150)
{
	std::cout << YELLOW <<
		"AForm default constructor called.\n" << RESET;
	return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExecute) : \
	name(name), isSigned(false), gradeSign(150), gradeExecute(150)
{
	std::cout << YELLOW <<
		"AForm constructor called.\n" << RESET;
	if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooLowException();
	const_cast<int &>(this->gradeSign) = gradeSign;
	const_cast<int &>(this->gradeExecute) = gradeExecute;
	return ;
}

AForm::AForm(const AForm &aform) : name("Boring bureaucrat"), isSigned(false), \
	gradeSign(150), gradeExecute(150)
{
	std::cout << YELLOW <<
		"AForm copy constructor called.\n" << RESET;
	*this = aform;
	return ;
}

AForm	&AForm::operator=(const AForm &aform)
{
	std::cout << YELLOW <<
		"AForm copy assignment operator called.\n" << RESET;
	if (this != &aform)
	{
		const_cast<std::string &>(this->name) = aform.getName();
		this->isSigned = aform.getIsSigned();
		const_cast<int &>(this->gradeSign) = aform.getGradeSign();
		const_cast<int &>(this->gradeExecute) = aform.getGradeExecute();
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << YELLOW <<
		"AForm destructor called.\n" << RESET;
	return ;
}

const std::string	AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int	AForm::getGradeSign(void) const
{
	return (this->gradeSign);
}

int	AForm::getGradeExecute(void) const
{
	return (this->gradeExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
	{
		std::cout << GREEN << bureaucrat.getName() << RESET
			<< " couldn't sign " << GREEN << this->getName() << RESET
			<< ". ";
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
	return ;
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!\n");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!\n");
}

const char	*AForm::FormNotSigned::what(void) const throw()
{
	return ("Form not signed!\n");
}

std::ostream &operator<<(std::ostream &lhs, const AForm &aform)
{
	std::string	isSigned;

	if (aform.getIsSigned() == true)
		isSigned = "Yes";
	else
		isSigned = "No";
	lhs << "Is " << GREEN << aform.getName() << RESET << " signed? "
		<< BLUE << isSigned << RESET << "\nGrade required to sign: "
		<< GREEN << aform.getGradeSign() << RESET
		<< "\nGrade required to execute: "
		<< GREEN << aform.getGradeExecute() << RESET << std::endl;
	return (lhs);
}
