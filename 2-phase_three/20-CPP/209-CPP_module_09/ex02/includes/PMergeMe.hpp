/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 17:18:24 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <algorithm>
# include <string>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class RPN
{
	private:
		std::stack<std::string>	parameters;
		std::stack<double>		numbers;
	public:
		RPN(void);
		RPN(const RPN &rpn);
		RPN	&operator=(const RPN &rpn);
		~RPN(void);
		void	rpn(std::string str);
		void	populateStack(std::string parameter);
		void	calculateResult(void);
};

#endif