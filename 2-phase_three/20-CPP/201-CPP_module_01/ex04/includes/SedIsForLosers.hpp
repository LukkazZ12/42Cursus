/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:19:00 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 19:26:19 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class	SedIsForLosers
{
	private:
		char			*s1;
		char			*s2;
		std::ifstream	inputFile;
		std::ofstream	outputFile;
	public:
		SedIsForLosers(void);
		SedIsForLosers(char **argv);
		~SedIsForLosers(void);
		void			replaceString(void);
};

#endif