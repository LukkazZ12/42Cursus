/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 12:48:38 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printChar(int c)
{
	std::cout << BLUE << "char: " << RESET << "'" << static_cast<char>(c) << "'" << std::endl;
	std::cout << RED << "int: " << RESET << c << std::endl;
	std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << YELLOW << "double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	printInt(long double number)
{
	int	integer = number;

	std::cout << BLUE << "char: " << RESET;
	if (integer >= 0 && integer <= 255)
	{
		if (integer >= 32 && integer <= 126)
			std::cout << "'" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "non displayble\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int: " << RESET << integer << std::endl;
	std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << YELLOW << "double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
}

void	printFloat(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << BLUE << "char: " << RESET;
	if (floor >= 0 && floor <= 255)
	{
		if (floor >= 32 && floor <= 126)
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayble\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int: " << RESET;
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible\n";
	std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	std::cout << YELLOW << "double: " << RESET << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printDouble(long double number, int decimals)
{
	double	floor = static_cast<double>(std::floor(number));

	std::cout << BLUE << "char: " << RESET;
	if (floor >= 0 && floor <= 255)
	{
		if (floor >= 32 && floor <= 126)
			std::cout << "'" << static_cast<char>(floor) << "'" << std::endl;
		else
			std::cout << "non displayble\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << RED << "int: " << RESET;
	if (floor >= -2147483649 && floor <= 2147483647)
	{
		if (floor < 0)
			floor++;
		std::cout << static_cast<int>(floor) << std::endl;
	}
	else
		std::cout << "impossible\n";
	std::cout << GREEN << "float: " << RESET;
	if (number < std::numeric_limits<float>::max() &&
		number > -std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(decimals) << static_cast<float>(number) << "f" << std::endl;
	else
		std::cout << "impossible\n";
	std::cout << YELLOW << "double: " << RESET << std::fixed << std::setprecision(decimals) << static_cast<double>(number) << std::endl;
}

void	printLiterals(int i, std::string str)
{
	std::cout << BLUE << "char: " << RESET << "impossible\n";
	std::cout << RED << "int: " << RESET << "impossible\n";
	if (i > 3)
		str[str.size() - 1] = '\0';
	std::cout << GREEN << "float: " << RESET << str << "f\n";
	std::cout << YELLOW << "double: " << RESET << str << std::endl;
}

void	printImpossible(void)
{
	std::cout << "The paramter is " << CYAN << "impossible" << RESET << ".\n";
	std::cout << BLUE << "char: " << RESET << "impossible\n";
	std::cout << RED << "int: " << RESET << "impossible\n";
	std::cout << GREEN << "float: " << RESET << "impossible\n";
	std::cout << YELLOW << "double: " << RESET << "impossible\n";
	return ;
}
