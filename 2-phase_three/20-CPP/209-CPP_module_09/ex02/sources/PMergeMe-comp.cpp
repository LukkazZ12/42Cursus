/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:23 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/26 15:51:10 by lucade-s         ###   ########.fr       */
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
	unsigned int				number;
	std::vector<int>			vector;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	itEnd;
	std::vector<int>::iterator	itNext;

	for (int i = 1; i < argc; i++)
	{
		if (!argv[i][0])
			throw std::runtime_error("Error: Empty string.");
		argv[i][0] == '+' ? j = 1 : j = 0;
		if (!argv[i][j])
			throw std::runtime_error("Error: It's not a integer.");
		for (; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Error: It's not a integer or it's a negative integer.");
		}
		number = atoi(argv[i]);
		if (strlen(argv[i]) > 10 || number > 2147483647)
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
	return ;
}

static unsigned int	generateJacobsthalNumbers(unsigned int j0, unsigned int j1)
{
	return (2 * j0 + j1);
}

static void	printTime (clock_t start, clock_t end, size_t size, std::string type)
{
	double	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double	usTime = time * 1000000.0;

	std::cout << "Time to process a range of " << GREEN << size << RESET
		<< " elements with std::" << YELLOW << type << RESET
		<< ": " << GREEN << usTime << RESET << " us\n";
	return ;
}

void	PMergeMe::populateContainers(int argc, char **argv)
{
	int	number;

	for (int i = 1; i < argc; i++)
	{
		number = atoi(argv[i]);
		this->unsortedVector.push_back(number);
		this->unsortedDeque.push_back(number);
		this->unsortedCompVector.push_back(number);
		this->unsortedCompDeque.push_back(number);
	}
	this->numberOfElements = unsortedVector.size();

	std::vector<int>::iterator	it = unsortedVector.begin();
	std::vector<int>::iterator	itEnd = unsortedVector.end();

	std::cout << YELLOW << "Before:\t\t" << RESET;
	for (; it != itEnd; it++)
		std::cout << *it << (it != itEnd - 1 ? " " : "\n");
	return ;
}

void	PMergeMe::createAndSortMainChainVector(void)
{
	std::vector<int>			mainChainAux;
	std::vector<int>::iterator	itNext;
	std::vector<int>::iterator	it = this->unsortedVector.begin();
	std::vector<int>::iterator	itEnd = this->unsortedVector.end();

	for (; it != itEnd; )
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			mainChainAux.push_back(*it);
			this->pendChainVector.push_back(*itNext);
		}
		else
		{
			mainChainAux.push_back(*itNext);
			this->pendChainVector.push_back(*it);
		}
		it++;
		it++;
	}
	if (this->straggler != -1)
	{
		this->sortedVector.push_back(this->straggler);
		this->unsortedVector.push_back(this->straggler);
	}
	it = mainChainAux.begin();
	itEnd = mainChainAux.end();
	for (; it != itEnd; it++)
		this->sortedVector.insert(std::upper_bound(this->sortedVector.begin(), \
			this->sortedVector.end(), *it), *it);
	return ;
}

void	PMergeMe::createAndSortMainChainCompVector(void)
{
	std::vector<int>			mainChainAux;
	std::vector<int>::iterator	itNext;
	std::vector<int>::iterator	it = this->unsortedCompVector.begin();
	std::vector<int>::iterator	itEnd = this->unsortedCompVector.end();

	for (; it != itEnd; )
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			mainChainAux.push_back(*it);
			this->pendChainCompVector.push_back(*itNext);
		}
		else
		{
			mainChainAux.push_back(*itNext);
			this->pendChainCompVector.push_back(*it);
		}
		it++;
		it++;
	}
	if (this->straggler != -1)
	{
		this->sortedCompVector.push_back(this->straggler);
		this->unsortedCompVector.push_back(this->straggler);
	}
	it = mainChainAux.begin();
	itEnd = mainChainAux.end();
	for (; it != itEnd; it++)
		this->sortedCompVector.insert(std::upper_bound(this->sortedCompVector.begin(), \
			this->sortedCompVector.end(), *it), *it);
	return ;
}

void	PMergeMe::createAndSortMainChainDeque(void)
{
	std::deque<int>				mainChainAux;
	std::deque<int>::iterator	itNext;
	std::deque<int>::iterator	it = this->unsortedDeque.begin();
	std::deque<int>::iterator	itEnd = this->unsortedDeque.end();

	for (; it != itEnd; )
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			mainChainAux.push_back(*it);
			this->pendChainDeque.push_back(*itNext);
		}
		else
		{
			mainChainAux.push_back(*itNext);
			this->pendChainDeque.push_back(*it);
		}
		it++;
		it++;
	}
	if (this->straggler != -1)
	{
		this->sortedDeque.push_back(this->straggler);
		this->unsortedDeque.push_back(this->straggler);
	}
	it = mainChainAux.begin();
	itEnd = mainChainAux.end();
	for (; it != itEnd; it++)
		this->sortedDeque.insert(std::upper_bound(this->sortedDeque.begin(), \
			this->sortedDeque.end(), *it), *it);
	return ;
}

void	PMergeMe::createAndSortMainChainCompDeque(void)
{
	std::deque<int>				mainChainAux;
	std::deque<int>::iterator	itNext;
	std::deque<int>::iterator	it = this->unsortedCompDeque.begin();
	std::deque<int>::iterator	itEnd = this->unsortedCompDeque.end();

	for (; it != itEnd; )
	{
		itNext = it;
		itNext++;
		if (*it > *itNext)
		{
			mainChainAux.push_back(*it);
			this->pendChainCompDeque.push_back(*itNext);
		}
		else
		{
			mainChainAux.push_back(*itNext);
			this->pendChainCompDeque.push_back(*it);
		}
		it++;
		it++;
	}
	if (this->straggler != -1)
	{
		this->sortedCompDeque.push_back(this->straggler);
		this->unsortedCompDeque.push_back(this->straggler);
	}
	it = mainChainAux.begin();
	itEnd = mainChainAux.end();
	for (; it != itEnd; it++)
		this->sortedCompDeque.insert(std::upper_bound(this->sortedCompDeque.begin(), \
			this->sortedCompDeque.end(), *it), *it);
	return ;
}

void	PMergeMe::insertionVector(void)
{
	unsigned int				j0 = 1;
	unsigned int				j1 = 1;
	unsigned int				swap;
	size_t						pendChainSize = this->pendChainVector.size();
	size_t						pendChainSizeAux = pendChainSize;
	size_t						begin;
	size_t						end;
	std::vector<int>::iterator	it = this->pendChainVector.begin();

	if (pendChainSize > 0)
		this->sortedVector.insert(std::upper_bound(this->sortedVector.begin(), \
			this->sortedVector.end(), *it), *it);
	it++;
	if (pendChainSize > 1)
		this->sortedVector.insert(std::upper_bound(this->sortedVector.begin(), \
			this->sortedVector.end(), *it), *it);
	if (pendChainSize)
		pendChainSizeAux--;
	while (pendChainSizeAux--)
	{
		swap = j1;
		j1 = generateJacobsthalNumbers(j0, j1);
		j0 = swap;
		if (j1 >= pendChainSize)
			j1 = pendChainSize - 1;
		begin = pendChainSize - j1;
		end = j1 - j0;
		std::vector<int>::iterator	itEnd = this->pendChainVector.end();
		while (begin--)
			itEnd--;
		begin = 0;
		while (begin++ < end)
		{
			this->sortedVector.insert(std::upper_bound(this->sortedVector.begin(), \
				this->sortedVector.end(), *itEnd), *itEnd);
			itEnd--;
		}
	}
	return ;
}

void	PMergeMe::insertionCompVector(void)
{
	std::vector<int>::iterator	it = this->pendChainCompVector.begin();
	std::vector<int>::iterator	itEnd = this->pendChainCompVector.end();

	while (it != itEnd)
	{
		this->sortedCompVector.insert(std::upper_bound(this->sortedCompVector.begin(), \
			this->sortedCompVector.end(), *it), *it);
		it++;
	}
	return ;
}

void	PMergeMe::insertionDeque(void)
{
	unsigned int				j0 = 1;
	unsigned int				j1 = 1;
	unsigned int				swap;
	size_t						pendChainSize = this->pendChainDeque.size();
	size_t						pendChainSizeAux = pendChainSize;
	size_t						begin;
	size_t						end;
	std::deque<int>::iterator	it = this->pendChainDeque.begin();

	if (pendChainSize > 0)
		this->sortedDeque.insert(std::upper_bound(this->sortedDeque.begin(), \
			this->sortedDeque.end(), *it), *it);
	it++;
	if (pendChainSize > 1)
		this->sortedDeque.insert(std::upper_bound(this->sortedDeque.begin(), \
			this->sortedDeque.end(), *it), *it);
	if (pendChainSize)
		pendChainSizeAux--;
	while (pendChainSizeAux--)
	{
		swap = j1;
		j1 = generateJacobsthalNumbers(j0, j1);
		j0 = swap;
		if (j1 >= pendChainSize)
			j1 = pendChainSize - 1;
		begin = pendChainSize - j1;
		end = j1 - j0;
		std::deque<int>::iterator	itEnd = this->pendChainDeque.end();
		while (begin--)
			itEnd--;
		begin = 0;
		while (begin++ < end)
		{
			this->sortedDeque.insert(std::upper_bound(this->sortedDeque.begin(), \
				this->sortedDeque.end(), *itEnd), *itEnd);
			itEnd--;
		}
	}
	return ;
}

void	PMergeMe::insertionCompDeque(void)
{
	std::deque<int>::iterator	it = this->pendChainCompDeque.begin();
	std::deque<int>::iterator	itEnd = this->pendChainCompDeque.end();

	while (it != itEnd)
	{
		this->sortedCompDeque.insert(std::upper_bound(this->sortedCompDeque.begin(), \
			this->sortedCompDeque.end(), *it), *it);
		it++;
	}
	return ;
}

void	PMergeMe::FordJohnson(int argc, char **argv)
{
	validateParameters(argc, argv);
	populateContainers(argc, argv);

	clock_t	startVector = clock();

	this->straggler = -1;
	foundStraggler(this->unsortedVector, this->straggler);
	createAndSortMainChainVector();
	insertionVector();

	clock_t	endVector = clock();

	clock_t	startCompVector = clock();

	this->straggler = -1;
	foundStraggler(this->unsortedCompVector, this->straggler);
	createAndSortMainChainCompVector();
	insertionCompVector();

	clock_t	endCompVector = clock();

	clock_t	startDeque = clock();

	this->straggler = -1;
	foundStraggler(this->unsortedDeque, this->straggler);
	createAndSortMainChainDeque();
	insertionDeque();

	clock_t	endDeque = clock();

	clock_t	startCompDeque = clock();

	this->straggler = -1;
	foundStraggler(this->unsortedCompDeque, this->straggler);
	createAndSortMainChainCompDeque();
	insertionCompDeque();

	clock_t	endCompDeque = clock();

	printMessage(this->sortedVector, "vector");
	printMessage(this->sortedCompVector, "comp-vector");
	printMessage(this->sortedDeque, "deque");
	printMessage(this->sortedDeque, "comp-deque");
	printTime(startVector, endVector, this->unsortedVector.size(), "vector");
	printTime(startCompVector, endCompVector, this->unsortedCompVector.size(), "comp-vector");
	printTime(startDeque, endDeque, this->unsortedDeque.size(), "deque");
	printTime(startCompDeque, endCompDeque, this->unsortedCompDeque.size(), "comp-deque");
	return ;
};
