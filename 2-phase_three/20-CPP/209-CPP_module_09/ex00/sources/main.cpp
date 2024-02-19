/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/19 18:18:35 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Invalid arguments.\n" << RESET;
		std::cerr << GREEN << "Usage: ./btc <filename>\n" << RESET;
		return (1);
	}
	BitcoinExchange	bitcoin;

	try
	{
		bitcoin.readDataBase();
		bitcoin.readFile(argv[1]);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << std::endl << RESET;
	}
	return (0);
}
