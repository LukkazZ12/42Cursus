/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 14:08:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
	return ;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	if (this != &rpn)
	{
		this->parameters = rpn.parameters;
		this->numbers = rpn.numbers;
	}
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

static double	add(double first, double second)
{
	return (first + second);
}

static double	subtract(double first, double second)
{
	return (first - second);
}

static double	multiply(double first, double second)
{
	return (first * second);
}

static double	divide(double first, double second)
{
	if (!second)
		throw std::runtime_error("Error: Couldn't divide by 0.");
	return (first / second);
}

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
	return ;
}
static void	validateNumbersOperations(std::string &str)
{
	std::string			subString;
	std::stringstream	line(str);

	while (std::getline(line, subString, ' '))
	{
		if (subString.size() != 1)
			throw std::runtime_error("Error: Invalid parameter.");
	}
	return ;
}

static bool	validateStr(std::string str)
{
	if (str.find_first_not_of("0123456789+-*/ \t\n\v\f\r") != std::string::npos)
		throw std::runtime_error("Error: Invalid parameter.");
	whitespacesToSpace(str);
	validateNumbersOperations(str);
	return (true);
}

void	RPN::calculateResult(void)
{
	std::string	parameter;
	double		(*f[4])(double first, double second) = {add, subtract, multiply, divide};
	double		first;
	double		second;

	while (this->parameters.size())
	{
		parameter = this->parameters.top();
		if (isdigit(parameter[0]))
		{
			std::istringstream	toDouble(parameter);
			float				value;

			toDouble >> value;
			this->numbers.push(value);
		}
		else if (this->numbers.size() >= 2)
		{
			second = this->numbers.top();
			this->numbers.pop();
			first = this->numbers.top();
			this->numbers.pop();
			if (parameter[0] == '+')
				this->numbers.push((*f[ADD])(first, second));
			else if (parameter[0] == '-')
				this->numbers.push((*f[SUB])(first, second));
			else if (parameter[0] == '*')
				this->numbers.push((*f[MULT])(first, second));
			else if (parameter[0] == '/')
				this->numbers.push((*f[DIV])(first, second));
		}
		else
			throw std::runtime_error("Error: Invalid parameter.");
		this->parameters.pop();
	}
	if (this->numbers.size() >= 2)
		throw std::runtime_error("Error: Invalid parameter.");
	return ;
}

void	RPN::populateStack(std::string parameter)
{
	std::string				subString;
	std::stringstream		line(parameter);
	std::stack<std::string>	parametersAux;

	while (std::getline(line, subString, ' '))
		parametersAux.push(subString);
	while (parametersAux.size())
	{
		this->parameters.push(parametersAux.top());
		parametersAux.pop();
	}
	return ;
};

void	RPN::rpn(std::string parameter)
{
	validateStr(parameter);
	populateStack(parameter);
	calculateResult();
	std::cout << GREEN << this->numbers.top() << RESET << std::endl;
	return ;
};
