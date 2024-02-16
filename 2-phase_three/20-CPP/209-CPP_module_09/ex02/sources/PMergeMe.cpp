/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/16 18:27:18 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe(void)
{
	return ;
}

PMergeMe::PMergeMe(const PMergeMe &merge)
{
	*this = merge;
	return ;
}

PMergeMe	&PMergeMe::operator=(const PMergeMe &merge)
{
	if (this != &merge)
	{
		this->unsortedVector = merge.unsortedVector;
		this->unsortedDeque = merge.unsortedDeque;
	}
	return (*this);
}

PMergeMe::~PMergeMe(void)
{
	return ;
}

static void	validateParameters(int argc, char **argv)
{
	size_t						j;
	float						number;
	std::vector<int>			vector;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	itEnd;
	std::vector<int>::iterator	itNext;

	for (int i = 1; i < argc; i++)
	{
		if (!argv[i][0])
			throw std::runtime_error("Error: Empty string.");
		argv[i][0] == '+' ? j = 1 : j = 0;
		for (; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Error: It's not a integer or it's a negative integer.");
		}
		number = atof(argv[i]);
		if (number > (float)2147483647)
			throw std::runtime_error("Error: Too large a integer.");
		vector.push_back(atoi(argv[i]));
	}
	std::sort(vector.begin(), vector.end());
	it = vector.begin();
	itEnd = vector.end();
	for (; it != itEnd; it++)
	{
		itNext = it;
		itNext++;
		if (itNext != itEnd)
		{
			if (*it == *itNext)
				throw std::runtime_error("Error: Duplicate integers.");
		}
	}
}

void	PMergeMe::sort(int argc, char **argv)
{
	validateParameters(argc, argv);
	return ;
};
