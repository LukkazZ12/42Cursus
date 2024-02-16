/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 20:18:17 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printChar(int c)
{
	std::cout << BLUE << "char:\t" << RESET << "'" << static_cast<char>(c) << "'" << std::endl;
	std::cout << RED << "int:\t" << RESET << static_cast<int>(c) << std::endl;
	std::cout << GREEN << "float:\t" << RESET << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << YELLOW << "double:\t" << RESET << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	printInt(long double number)
{
	int	integer = number;

	std::cout << BLUE << "char:\t" << RESET;
	if (integer >= 0 && integer <= 255)
	{
		if (isprint(integer))
			std::cout << "'" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int:\t" << RESET << static_cast<int>(number) << std::endl;
	std::cout << GREEN << "float:\t" << RESET << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << YELLOW << "double:\t" << RESET << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void	printFloat(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << BLUE << "char:\t" << RESET;
	if (floor >= 0 && floor <= 255)
	{
		if (isprint(floor))
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int:\t" << RESET;
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible\n";
	std::cout << GREEN << "float:\t" << RESET << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	std::cout << YELLOW << "double:\t" << RESET << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printDouble(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << BLUE << "char:\t" << RESET;
	if (floor >= 0 && floor <= 255)
	{
		if (isprint(floor))
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int:\t" << RESET;
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible\n";
	std::cout << GREEN << "float:\t" << RESET;
	if (number < std::numeric_limits<float>::max() &&
		number > -std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	else
		std::cout << "impossible\n";
	std::cout << YELLOW << "double:\t" << RESET << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printLiterals(int i, std::string str)
{
	std::cout << BLUE << "char:\t" << RESET << "impossible\n";
	std::cout << RED << "int:\t" << RESET << "impossible\n";
	if (i > 3)
		str[str.size() - 1] = '\0';
	std::cout << GREEN << "float:\t" << RESET << str << "f\n";
	std::cout << YELLOW << "double:\t" << RESET << str << std::endl;
}

void	printImpossible(void)
{
	std::cout << "The parameter is " << CYAN << "impossible" << RESET << ".\n";
	std::cout << BLUE << "char:\t" << RESET << "impossible\n";
	std::cout << RED << "int:\t" << RESET << "impossible\n";
	std::cout << GREEN << "float:\t" << RESET << "impossible\n";
	std::cout << YELLOW << "double:\t" << RESET << "impossible\n";
	return ;
}
