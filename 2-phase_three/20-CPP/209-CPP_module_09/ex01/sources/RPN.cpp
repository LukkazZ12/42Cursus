/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/15 18:47:30 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isWhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static void	whitespacesToSpace(std::string &str)
{
	unsigned int	i = 0;

	while (str[i])
	{
		if (isWhitespace(str[i]))
			str[i] = ' ';
		i++;
	}
}

static void	validateNumbersOperations(std::string &str)
{
	// int					i = 0;
	std::string			subString;
	std::stringstream	line(str);

	while (std::getline(line, subString, ' '))
	{
		if (subString.size() != 1)
			throw std::runtime_error("Invalid parameter.");
		// else if (i == 1)
		// 	subString != "value" ? \
		// 		throw std::runtime_error("Invalid parameter.") : i++;
		// else
		// 	throw std::runtime_error("Invalid parameter.");
	}
}

static bool	validateStr(std::string str)
{
	// unsigned int	i = 0;

	if (str.find_first_not_of("0123456789+-*/ \t\n\v\f\r") != std::string::npos)
		throw std::runtime_error("Invalid str.");
	whitespacesToSpace(str);
	validateNumbersOperations(str);
	return (true);
	// while (parameter[i])
	// {
	// 	while (is_whitespace(parameter[i]))
	// 		i++;
		
	// }
}

void	rpn(std::string parameter)
{
	validateStr(parameter);
	return ;
};
