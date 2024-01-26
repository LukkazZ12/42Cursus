/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/26 20:15:23 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExecute);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form(void);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &lhs, const Form &Form);

#endif