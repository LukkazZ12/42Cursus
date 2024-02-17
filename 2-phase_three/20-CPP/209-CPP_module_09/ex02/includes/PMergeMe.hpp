/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 20:37:51 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <cstdlib>
#include <algorithm>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class PMergeMe
{
	private:
		// int					straggler;
		// void				sortVector();
		int					numberOfElements;
		std::vector<int>	unsortedVector;
		std::vector<int>	sortedVector;
		// void				sortDeque();
		std::deque<int>		unsortedDeque;
		std::deque<int>		sortedDeque;
	public:
		PMergeMe();
		// PMergeMe(std::vector<int> vector, std::deque<int> deque);
		PMergeMe(const PMergeMe &merge);
		PMergeMe &operator=(const PMergeMe &merge);
		~PMergeMe();
		void				sort(int argc, char **argv);
		void				populateContainers(int argc, char **argv);
		void				FordJohnsonVector(void);
		// std::deque<int>		getSortedDeque() const;
	
};

#endif