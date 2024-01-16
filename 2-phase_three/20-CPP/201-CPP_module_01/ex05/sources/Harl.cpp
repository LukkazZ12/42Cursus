/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:27:51 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/16 18:25:24 by lucade-s         ###   ########.fr       */
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
}

void	Harl::info(void)
{
	std::cout << BLUE << "[ INFO ]\n" << RESET
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]\n" << RESET
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working "
		<< "here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\n" << RESET
		<< "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->level[i].first)
		{
			(this->*(this->level[i].second))();
			return ;
		}
	}
}
