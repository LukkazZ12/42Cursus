/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/09 16:38:44 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	{
		std::cout << YELLOW << "Subject test\n\n" << RESET;
		MutantStack<int>	st;

		st.push(5);
		st.push(17);
		std::cout << "St top: " << GREEN << st.top() << "\n" << RESET;
		st.pop();
		std::cout << "St size: " << GREEN << st.size() << "\n" << RESET;
		st.push(3);
		st.push(5);
		st.push(737);
		st.push(42);
		st.push(0);

		MutantStack<int>::iterator	it = st.begin();
		MutantStack<int>::iterator	ite = st.end();

		it++;
		it--;
		std::cout << GREEN << "\nIterators:\n" << RESET;
		std::cout << "St elements: ";
		while (it != ite)
		{
			std::cout << GREEN << *it << RESET << (it < ite - 1 ? ", " : "\n");
			it++;
		}

		MutantStack<int>::reverse_iterator	rit = st.rbegin();
		MutantStack<int>::reverse_iterator	rite = st.rend();

		rit++;
		rit--;
		std::cout << GREEN << "\nReserve iterators:\n" << RESET;
		std::cout << "St elements: ";
		while (rit != rite)
		{
			std::cout << GREEN << *rit << RESET << (rit < rite - 1 ? ", " : "\n");
			rit++;
		}
		std::stack<int>	s(st);
	}
	{
		std::cout << YELLOW << "\nCopy test\n\n" << RESET;
		MutantStack<int>	st;

		st.push(58);
		st.push(1706);
		st.push(35546);
		st.push(5);
		st.push(7378);
		st.push(42);
		st.push(-9842);
		st.push(0);

		std::cout << GREEN << "Copy\n" << RESET;
		MutantStack<int>	a = st;
		MutantStack<int>	b(st);

		MutantStack<int>::iterator	it = st.begin();
		MutantStack<int>::iterator	ite = st.end();
		std::cout << "St elements: ";
		while (it != ite)
		{
			std::cout << GREEN << *it << RESET << (it < ite - 1 ? ", " : "\n");
			it++;
		}

		MutantStack<int>::iterator	itA = a.begin();
		MutantStack<int>::iterator	iteA = a.end();
		
		std::cout << "A elements: ";
		while (itA != iteA)
		{
			std::cout << GREEN << *itA << RESET << (itA < iteA - 1 ? ", " : "\n");
			itA++;
		}

		MutantStack<int>::iterator	itB = b.begin();
		MutantStack<int>::iterator	iteB = b.end();

		std::cout << "B elements: ";
		while (itB != iteB)
		{
			std::cout << GREEN << *itB << RESET << (itB < iteB - 1 ? ", " : "\n");
			itB++;
		}

		std::cout << GREEN << "\nIs it a deep copy?\n" << RESET;
		st.push(1207);
		it = st.begin();
		ite = st.end();
		std::cout << "St elements: ";
		while (it != ite)
		{
			std::cout << GREEN << *it << RESET << (it < ite - 1 ? ", " : "\n");
			it++;
		}

		a.pop();
		itA = a.begin();
		iteA = a.end();
		std::cout << "A elements: ";
		while (itA != iteA)
		{
			std::cout << GREEN << *itA << RESET << (itA < iteA - 1 ? ", " : "\n");
			itA++;
		}

		b.pop();
		b.pop();
		itB = b.begin();
		iteB = b.end();
		std::cout << "B elements: ";
		while (itB != iteB)
		{
			std::cout << GREEN << *itB << RESET << (itB < iteB - 1 ? ", " : "\n");
			itB++;
		}

		MutantStack<int>::reverse_iterator	rit = st.rbegin();
		MutantStack<int>::reverse_iterator	rite = st.rend();
		std::cout << GREEN << "\nReverse iterators:\n" << RESET;
		std::cout << "St elements: ";
		while (rit != rite)
		{
			std::cout << GREEN << *rit << RESET << (rit < rite - 1 ? ", " : "\n");
			rit++;
		}

		MutantStack<int>::reverse_iterator	ritA = a.rbegin();
		MutantStack<int>::reverse_iterator	riteA = a.rend();
		
		std::cout << "A elements: ";
		while (ritA != riteA)
		{
			std::cout << GREEN << *ritA << RESET << (ritA < riteA - 1 ? ", " : "\n");
			ritA++;
		}

		MutantStack<int>::reverse_iterator	ritB = b.rbegin();
		MutantStack<int>::reverse_iterator	riteB = b.rend();

		std::cout << "B elements: ";
		while (ritB != riteB)
		{
			std::cout << GREEN << *ritB << RESET << (ritB < riteB - 1 ? ", " : "\n");
			ritB++;
		}
	}
	{
		std::cout << YELLOW << "\nMutantStack vs. list\n\n" << RESET;
		MutantStack<int>	st;
		std::list<int>		lst;

		for (int i = 0; i < 10; i++)
		{
			st.push(i);
			lst.push_back(i);
		}
		std::cout << "St size: " << GREEN << st.size() << RESET;
		std::cout << "\nLst size: " << GREEN << lst.size() << RESET;
		
		MutantStack<int>::iterator	itSt = st.begin();
		MutantStack<int>::iterator	iteSt = st.end();
		std::list<int>::iterator	itLst = lst.begin();
		std::list<int>::iterator	iteLst = lst.end();
		
		std::cout << "\nSt elements: ";
		while (itSt != iteSt)
		{
			std::cout << GREEN << *itSt << RESET << (itSt < iteSt - 1 ? ", " : "\n");
			itSt++;
		}
		std::cout << "Lst elements: ";
		while (itLst != iteLst)
			std::cout << GREEN << *itLst << RESET << (++itLst != iteLst ? ", " : "\n");
	}
	return (0);
}
