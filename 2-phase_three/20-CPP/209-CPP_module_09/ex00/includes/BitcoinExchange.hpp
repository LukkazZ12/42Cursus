/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 17:19:13 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cmath>
# include <iomanip>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

# define DATA			"files/data.csv"
# define NORMAL_YEAR	2
# define LEAP_YEAR		3
# define T_E_MONTH		5
# define T_N_MONTH		7
# define T_MONTH		11
# define T_O_MONTH		13
# define FEB			2
# define APR			4
# define JUN			6
# define SEP			9
# define NOV			11

class BitcoinExchange
{
	private:
		std::map<std::string, float>	dataBase;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &bitcoin);
		BitcoinExchange	&operator=(const BitcoinExchange &bitcoin);
		~BitcoinExchange(void);
		void	readFile(const std::string &filename);
		void	readDataBase(void);
		float	searchInDataBase(const std::string &date);
		void	printMessage(std::string str, float value);
};

#endif