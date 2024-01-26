/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/26 20:12:17 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Boring form"), isSigned(false), \
	gradeSign(150), gradeExecute(150)
{
	std::cout << GREEN <<
		"Form default constructor called.\n" << RESET;
	return ;
}

Form::Form(const std::string name, int gradeSign, int gradeExecute) : \
	name(name), isSigned(false), gradeSign(150), gradeExecute(150)
{
	std::cout << GREEN <<
		"Form constructor called.\n" << RESET;
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	const_cast<int &>(this->gradeSign) = gradeSign;
	const_cast<int &>(this->gradeExecute) = gradeExecute;
	return ;
}

Form::Form(const Form &form) : name("Boring bureaucrat"), isSigned(false), \
	gradeSign(150), gradeExecute(150)
{
	std::cout << GREEN <<
		"Form copy constructor called.\n" << RESET;
	*this = form;
	return ;
}

Form	&Form::operator=(const Form &form)
{
	std::cout << GREEN <<
		"Form copy assignment operator called.\n" << RESET;
	if (this != &form)
	{
		const_cast<std::string &>(this->name) = form.getName();
		this->isSigned = form.getIsSigned();
		const_cast<int &>(this->gradeSign) = form.getGradeSign();
		const_cast<int &>(this->gradeExecute) = form.getGradeExecute();
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << GREEN <<
		"Form destructor called.\n" << RESET;
	return ;
}

const std::string	Form::getName(void) const
{
	return (this->name);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int	Form::getGradeSign(void) const
{
	return (this->gradeSign);
}

int	Form::getGradeExecute(void) const
{
	return (this->gradeExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->isSigned = true;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &lhs, const Form &form)
{
	lhs << "Form " << form.getName() << ", is signed? " << form.getIsSigned() << ", grade required to sign: "
		<< form.getGradeSign() << ", grade required to execute: " << form.getGradeExecute();
	return (lhs);
}
