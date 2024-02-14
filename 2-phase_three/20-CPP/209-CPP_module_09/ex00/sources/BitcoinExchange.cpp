/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:38 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/14 20:34:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << BLUE <<
		"BitcoinExchange default constructor called.\n" << RESET;
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoin)
{
	std::cout << BLUE <<
		"BitcoinExchange copy constructor called.\n" << RESET;
	*this = bitcoin;
	return ;
}
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &bitcoin)
{
	if (this != &bitcoin)
		this->dataBase = bitcoin.dataBase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << BLUE <<
		"BitcoinExchange default destructor called.\n" << RESET;
	return ;
}

static bool	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static void	ltrim(std::string &str)
{
	size_t	i = 0;

	while (i < str.size() && is_whitespace(str[i]))
		i++;
	str = str.substr(i);
}

static void	rtrim(std::string &str)
{
	size_t	i = str.size();

	while (i > 0 && is_whitespace(str[i - 1]))
		i--;
	str = str.substr(0, i);
}

static void	trim(std::string &str)
{
	ltrim(str);
	rtrim(str);
}

static void	validateHeader(const std::string &header)
{
	int					i = 0;
	std::string			subString;
	std::stringstream	line(header);

	while (std::getline(line, subString, '|'))
	{
		if (!i)
		{
			trim(subString);
			if (subString != "date")
				throw std::runtime_error("Invalid header.");
		}
		else if (i == 1)
		{
			trim(subString);
			if (subString != "value")
				throw std::runtime_error("Invalid header.");
		}
		else
			throw std::runtime_error("Invalid header.");
		i++;
	}
}

static bool	validateYear(std::string &yearStr, int &ver)
{
	ltrim(yearStr);

	size_t	size = yearStr.size();

	if (size != 4)
		return (false);
	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(yearStr[i]))
			return (false);
	}

	std::istringstream	toInt(yearStr);
	int					year;

	toInt >> year;
	if (year < 2009)
		return (false);
	if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
		ver = LEAP_YEAR;
	else
		ver = NORMAL_YEAR;
	return (true);
}

static bool	validateMonth(std::string &monthStr, int &ver)
{
	size_t	size = monthStr.size();

	if (size != 2)
		return (false);
	for (int i = 0; i < 2; i++)
	{
		if (!isdigit(monthStr[i]))
			return (false);
	}

	std::istringstream	toInt(monthStr);
	int					month;

	toInt >> month;
	if (month < 1 || month > 12)
		return (false);
	if (month == FEB)
	{ 
		if (ver == NORMAL_YEAR)
			ver = T_E_MONTH;
		else
			ver = T_N_MONTH;
	}
	else if (month == APR || month == JUN || month == SEP || month == NOV)
		ver = T_MONTH;
	else
		ver = T_O_MONTH;
	return (true);
}

static bool	validateDay(std::string &dayStr, int &ver)
{
	rtrim(dayStr);

	size_t	size = dayStr.size();

	if (size != 2)
		return (false);
	for (int i = 0; i < 2; i++)
	{
		if (!isdigit(dayStr[i]))
			return (false);
	}

	std::istringstream	toInt(dayStr);
	int					day;

	toInt >> day;
	if ((ver == T_E_MONTH && day > 28) || (ver == T_N_MONTH && day > 29) || \
		(ver == T_MONTH && day > 30) || (ver == T_O_MONTH && day > 31))
		return (false);
	return (true);
}

static bool	validateDate(std::string &date)
{
	int					ver = 0;
	int					i = 0;
	std::string			subString;
	std::stringstream	line(date);

	while (std::getline(line, subString, '-'))
	{
		if (!i)
		{
			if (!validateYear(subString, ver))
				return (false);
		}
		else if (i == 1)
		{
			if (!validateMonth(subString, ver))
				return (false);
		}
		else if (i == 2)
		{
			if (!validateDay(subString, ver))
				return (false);
		}
		else
			return (false);
		i++;
	}
	trim(date);
	if (date == "2009-01-01")
		return (false);
	return (true);
}

static std::string	validateValue(std::string &value, bool &valueError)
{
	trim(value);

	int			dot = 0;
	int			i = 0;
	int			size = (int)value.size() - 1;
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (value[0] == '+' || value[0] == '-')
		i++;
	while(i < size)
	{
		if (value[i] != '.' && !isdigit(value[i]))
			return ("Error: bad input => " + value);
		if (value[i] == '.')
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
	if (dot > 1 || value[0] == '.' || value[i - 1] == '.')
		return ("Error: bad input => " + value);
	number = atof(value.c_str());
	if (number > 1000)
		return ("Error: too large a number.");
	if (number < 0)
		return ("Error: not a positive number.");
	valueError = false;
	return ("OK");
}

void	BitcoinExchange::readFile(const std::string &filename)
{
	int				i;
	bool			valueError;
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		subString;
	std::string		subStringAux;

	if (!file.is_open())
		throw std::runtime_error("Couldn't open de file.");
	std::getline(file, line);
	validateHeader(line);
	while (std::getline(file, line))
	{
		i = 0;
		std::stringstream	lineSplit(line);
		while (std::getline(lineSplit, subString, '|'))
		{
			valueError = true;
			if (!i)
			{
				if (!validateDate(subString))
				{
					std::cerr << RED << "Error: bad input => " << subString << RESET << std::endl;
					break ;
				}
				else
					subStringAux = subString;
			}
			else if (i == 1)
			{
				std::string	message = validateValue(subString, valueError);
				if (valueError)
				{
					std::cerr << RED << message << RESET << std::endl;
					break ;
				}
				else
				{
					std::istringstream	toFloat(subString);
					float				value;

					toFloat >> value;
					this->dataBase[subStringAux] = value;
				}
			}
			else
			{
				std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
					break ;
			}
			i++;
		}
	}
	// std::map<std::string, float>::iterator	it;
	// for (it = this->dataBase.begin(); it != this->dataBase.end(); it++)
	// {
	// 	std::cout << "Chave: " << it->first << ", Valor: " << it->second << std::endl;
	// }
	return ;
}

