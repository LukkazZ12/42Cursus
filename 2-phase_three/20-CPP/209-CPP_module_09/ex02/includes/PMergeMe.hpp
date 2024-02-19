/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/19 18:19:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <cstdlib>
# include <algorithm>
# include <ctime>
# include <typeinfo>
# include <cstring>

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
		int					straggler;
		int					numberOfElements;
		std::vector<int>	sortedVector;
		std::vector<int>	unsortedVector;
		std::vector<int>	pendChainVector;
		std::deque<int>		sortedDeque;
		std::deque<int>		unsortedDeque;
		std::deque<int>		pendChainDeque;
	public:
		PMergeMe(void);
		PMergeMe(const PMergeMe &merge);
		PMergeMe &operator=(const PMergeMe &merge);
		~PMergeMe(void);
		void				FordJohnson(int argc, char **argv);
		void				populateContainers(int argc, char **argv);
		void				createAndSortMainChainVector(void);
		void				createAndSortMainChainDeque(void);
		void				insertionVector(void);
		void				insertionDeque(void);
};

template <typename T>
void	foundStraggler(T &container, int &straggler)
{
	typename T::iterator	itStraggler;

	if (container.size() % 2)
	{
		itStraggler = container.end();
		itStraggler--;
		straggler = *itStraggler;
		container.pop_back();
	}
	return ;
}

template <typename T>
void	printMessage(T sorted, std::string type)
{
	typename T::iterator	it = sorted.begin();
	typename T::iterator	itEnd = sorted.end();

	std::cout << GREEN <<"After (" << type << "):\t" << RESET;
	for (; it != itEnd; it++)
		std::cout << *it << (it != itEnd - 1 ? " " : "\n");
	return ;
}

#endif