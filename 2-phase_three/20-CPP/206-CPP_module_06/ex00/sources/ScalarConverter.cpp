/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/31 21:58:22 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << BLUE <<
		"ScalarConverter default constructor called.\n" << RESET;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	std::cout << BLUE <<
		"ScalarConverter copy constructor called.\n" << RESET;
	*this = scalar;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &scalar)
{
	std::cout << BLUE <<
		"ScalarConverter copy assignment operator called.\n" << RESET;
	(void)scalar;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << BLUE <<
		"ScalarConverter default destructor called.\n" << RESET;
	return ;
}

static bool	isChar(std::string str)
{
	if (str.size() > 1 || !isprint(str[0]))
		return (false);
	std::cout << "The parameter is " << BLUE << "char.\n" << RESET;
	printChar(str[0]);
	return (true);
}

static bool	isInt(std::string str)
{
	int		i;
	double	number;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while(str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	number = atof(str.c_str());
	if (number > 2147483647 || number < -2147483648)
		return (false);
	std::cout << "The parameter is " << RED << "int.\n" << RESET;
	printInt(number);
	return (true);
}

static bool	isFloat(std::string str)
{
	int			dot = 0;
	int			i = 0;
	int			size = (int)str.size() - 1;
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while(i < size)
	{
		if (str[i] != '.' && !isdigit(str[i]))
			return (false);
		if (str[i] == '.')
		{
			dot++;
			hasDot = true;
		}
		if (hasDot)
			decimals++;
		i++;
	}
	if (decimals == -1)
		decimals = 1;
	if (str[i] != 'f' || dot > 1 || str[0] == '.' || str[i - 1] == '.')
		return (false);
	number = atof(str.c_str());
	if (number > std::numeric_limits<float>::max() ||
		number < -std::numeric_limits<float>::max())
		return (false);
	std::cout << "The parameter is " << GREEN << "float.\n" << RESET;
	printFloat(number, decimals);
	return (true);
}

static bool	isDouble(std::string str)
{
	int			dot = 0;
	int			i = 0;
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while(str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			dot++;
			hasDot = true;
		}
		if (hasDot)
			decimals++;
		i++;
	}
	if (decimals == -1)
		decimals = 1;
	if (dot > 1 || str[0] == '.' || str[i - 1] == '.')
		return (false);
	number = atof(str.c_str());
	if (number > std::numeric_limits<double>::max() ||
		number < -std::numeric_limits<double>::max())
		return (false);
	std::cout << "The parameter is " << GREEN << "double.\n" << RESET;
	printDouble(number, decimals);
	return (true);
}

static bool	isPseudoLiterals(std::string str)
{
	std::string pseudoLiterals[]= {
		"inf",
		"+inf",
		"-inf",
		"nan",
		"nanf",
		"inff",
		"+inff",
		"-inff"
	};

	for (int i = 0; i < 8 ; i++)
		if (pseudoLiterals[i] == str)
		{
			std::cout << "The parameter is " << MAGENTA <<  "pseudo literal.\n" << RESET;
			printLiterals(i, str);
			return (true);
		}
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
	if (str.size() == 0)
	{
		printImpossible();
		return ;
	}
	else
	{
		if (isChar(str))
			return ;
		else if (isInt(str))
			return ;
		else if (isFloat(str))
			return ;
		else if (isDouble(str))
			return ;
		else if (isPseudoLiterals(str))
			return ;
		else
		{
			printImpossible();
			return ;
		}
	}
}
