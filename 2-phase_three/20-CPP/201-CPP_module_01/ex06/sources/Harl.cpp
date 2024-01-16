/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:27:51 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/16 18:24:44 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->level[0] = std::make_pair("DEBUG", &Harl::debug);
	this->level[1] = std::make_pair("INFO", &Harl::info);
	this->level[2] = std::make_pair("WARNING", &Harl::warning);
	this->level[3] = std::make_pair("ERROR", &Harl::error);
	std::cout << BLUE << "Created Harl.\n\n" << RESET;
	return ;
}

Harl::~Harl(void)
{
	std::cout << BLUE << "Destroed Harl.\n" << RESET;
	return ;
}

void	Harl::debug(void)
{
	std::cout << GREEN << "[ DEBUG ]\n" << RESET
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger.\n\n";
	(this->*level[1].second)();
}

void	Harl::info(void)
{
	std::cout << BLUE << "[ INFO ]\n" << RESET
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!\n\n";
	(this->*level[2].second)();
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]\n" << RESET
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working "
		<< "here since last month.\n\n";
	(this->*level[3].second)();
}

void	Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\n" << RESET
		<< "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == this->level[i].first)
			break ;
	}
	switch (i)
	{
		case DEBUG:
			(this->*(this->level[0].second))();
			break ;
		case INFO:
			(this->*(this->level[1].second))();
			break ;
		case WARNING:
			(this->*(this->level[2].second))();
			break ;
		case ERROR:
			(this->*(this->level[3].second))();
			break ;
		default:
			std::cout << CYAN
				<< "[ Probably complaining about insignificant problems ]\n" << RESET;
			break ;
	}
	return ;
}
