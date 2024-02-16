/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 17:44:20 by lucade-s         ###   ########.fr       */
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

static void	validateNumbersOperations(std::string &str)
{
	std::string			subString;
	std::stringstream	line(str);

	while (std::getline(line, subString, ' '))
	{
		if (subString.size() > 1)
			throw std::runtime_error("Error: Invalid parameter.");
	}
	return ;
}

static void	validateStr(std::string str)
{
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error("Error: Invalid parameter.");
	validateNumbersOperations(str);
	return ;
}

void	RPN::calculateResult(void)
{
	std::string	parameter;
	double		first;
	double		second;

	while (this->parameters.size())
	{
		parameter = this->parameters.top();
		if (isdigit(parameter[0]))
		{
			std::istringstream	toDouble(parameter);
			double				value;

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
				this->numbers.push(add(first, second));
			else if (parameter[0] == '-')
				this->numbers.push(subtract(first, second));
			else if (parameter[0] == '*')
				this->numbers.push(multiply(first, second));
			else if (parameter[0] == '/')
				this->numbers.push(divide(first, second));
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
	{
		if (subString[0])
			parametersAux.push(subString);
	}
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
