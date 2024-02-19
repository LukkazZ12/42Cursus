/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:38 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/19 15:24:46 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoin)
{
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
	return ;
}

static bool	isWhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static void	ltrim(std::string &str)
{
	size_t	i = 0;

	while (i < str.size() && isWhitespace(str[i]))
		i++;
	str = str.substr(i);
}

static void	rtrim(std::string &str)
{
	size_t	i = str.size();

	while (i > 0 && isWhitespace(str[i - 1]))
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

	if (header[header.size() - 1] == '|')
		throw std::runtime_error("Invalid header.");
	while (std::getline(line, subString, '|'))
	{
		trim(subString);
		if (!i)
			subString != "date" ? \
				throw std::runtime_error("Invalid header.") : i++;
		else if (i == 1)
			subString != "value" ? \
				throw std::runtime_error("Invalid header.") : i++;
		else
			throw std::runtime_error("Invalid header.");
	}
	if (i < 2)
		throw std::runtime_error("Invalid header.");
	return ;
}

static bool	validateYear(std::string &yearStr, int &ver)
{
	if (yearStr.size() != 4)
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
	(year % 100 != 0 && year % 4 == 0) || year % 400 == 0 ? \
		ver = LEAP_YEAR : ver = REGULAR_YEAR;
	return (true);
}

static bool	validateMonth(std::string &monthStr, int &ver)
{
	if (monthStr.size() != 2)
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
		ver == REGULAR_YEAR ? ver = T_E_MONTH : ver = T_N_MONTH;
	else
		month == APR || month == JUN || month == SEP || month == NOV ? \
			ver = T_MONTH : ver = T_O_MONTH;
	return (true);
}

static bool	validateDay(std::string &dayStr, int &ver)
{
	if (dayStr.size() != 2)
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

	if (date.size() != 10)
		return (false);
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
	if (date == "2009-01-01" || i < 3)
		return (false);
	return (true);
}

static std::string	validateValue(std::string &value, bool &valueError)
{
	int			dot = 0;
	int			i = 0;
	int			size = (int)value.size();
	int			decimals = -1;
	bool		hasDot = false;
	long double	number;

	if (value[0] == '+' || value[0] == '-')
	{
		i++;
		if (i == size)
			return ("Error: bad input => " + value);
	}
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
	if (dot > 1 || value[0] == '.' || value[i] == '.')
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
	float			value;
	bool			valueError;
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		subString;
	std::string		subStringAux;

	if (!file.is_open())
		throw std::runtime_error("Couldn't open the input file.");
	std::getline(file, line);
	trim(line);
	validateHeader(line);
	while (std::getline(file, line))
	{
		i = 0;
		std::stringstream	lineSplit(line);
		while (std::getline(lineSplit, subString, '|'))
		{
			valueError = true;
			trim(subString);
			if (!subString[0])
				i = 2;
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

					toFloat >> value;
				}
			}
			else
			{
				std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
				i = 3;
					break ;
			}
			i++;
		}
		if (i == 2)
			printMessage(subStringAux, value);
	}
	file.close();
	return ;
}

void	BitcoinExchange::readDataBase(void)
{
	int				i;
	std::ifstream	file(DATA);
	std::string		line;
	std::string		subString;
	std::string		subStringAux;

	if (!file.is_open())
		throw std::runtime_error("Couldn't open the database file.");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		i = 0;
		std::stringstream	lineSplit(line);
		while (std::getline(lineSplit, subString, ','))
		{
			if (!i)
				subStringAux = subString;
			else if (i == 1)
			{
				std::istringstream	toFloat(subString);
				float				value;

				toFloat >> value;
				this->dataBase[subStringAux] = value;
			}
			i++;
		}
	}
	file.close();
	return ;
}

float	BitcoinExchange::searchInDataBase(const std::string &date)
{
	std::map<std::string, float>::iterator	it;
	std::map<std::string, float>::iterator	itAux;
	std::map<std::string, float>::iterator	itBegin = this->dataBase.begin();
	std::map<std::string, float>::iterator	itEnd = this->dataBase.end();

	for (it = itBegin; it != itEnd; it++)
	{
		itAux = it;
		itAux++;
		if (date == it->first || (itAux != itEnd && date \
			> it->first && date < itAux->first))
			return (it->second);
	}
	return ((--it)->second);
};

void	BitcoinExchange::printMessage(std::string str, float value)
{
	float		monetaryUnits = value * searchInDataBase(str);
	std::string	bitcoin;
	
	value <= 1 ? bitcoin = "bitcoin" : bitcoin = "bitcoins";
	std::cout << YELLOW << str << RESET << " => " << GREEN << std::fixed << std::setprecision(2)
		<< value << RESET << " " << bitcoin << ": " << GREEN << std::fixed << std::setprecision(2)
		<< monetaryUnits << RESET << " m.u.\n";
	return ;
}
