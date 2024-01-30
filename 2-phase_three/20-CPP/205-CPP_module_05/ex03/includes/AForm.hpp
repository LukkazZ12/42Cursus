/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/27 18:31:12 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public:
		AForm(void);
		AForm(const std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm &aform);
		AForm &operator=(const AForm &aform);
		virtual ~AForm(void);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &bureaucrat) const = 0;
};

std::ostream &operator<<(std::ostream &lhs, const AForm &aform);

#endif