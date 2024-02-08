/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/08 19:08:27 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	{
		std::cout << YELLOW << "Test 1 (vector)\n\n" << RESET;

		std::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(0);
		vec.push_back(-125);
		vec.push_back(0);
		vec.push_back(-65);

		std::cout << GREEN << "vec: " << RESET;
		for(int j = 0; j < 5; j++)
			std::cout << vec[j] << (j != 4 ? ", " : "\n\n"); 
		{
			int				value = 1;
			unsigned int	it = easyfind(vec, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = 0;
			unsigned int	it = easyfind(vec, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = -125;
			unsigned int	it = easyfind(vec, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = -65;
			unsigned int	it = easyfind(vec, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int					value = 8;
			try
			{
				unsigned int	it = easyfind(vec, value);
				std::cout << it << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << BLUE << value << RED << e.what() << std::endl << RESET;
			}
		}
	}
	{
		std::cout << YELLOW << "\nTest 2 (list)\n\n" << RESET;

		std::list<int>	lst;
		lst.push_back(5689752);
		lst.push_back(-9855);
		lst.push_back(5);
		lst.push_front(-9855);
		lst.push_front(12);

		std::cout << GREEN << "lst: " << RESET;
		std::list<int>::iterator	i = lst.begin();
		for(int j = 0; j < 5; j++)
		{
			std::cout << *i << (j != 4 ? ", " : "\n\n");
			std::advance(i, 1); 
		}
		{
			int				value = 5689752;
			unsigned int	it = easyfind(lst, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = -9855;
			unsigned int	it = easyfind(lst, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = 5;
			unsigned int	it = easyfind(lst, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = 12;
			unsigned int	it = easyfind(lst, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int					value = -894546;
			try
			{
				unsigned int	it = easyfind(lst, value);
				std::cout << it << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << BLUE << value << RED << e.what() << std::endl << RESET;
			}
		}
	}
	{
		std::cout << YELLOW << "\nTest 3 (deque)\n\n" << RESET;
		
		std::deque<int>	deq;
		deq.push_front(-12);
		deq.push_front(14);
		deq.push_front(0);
		deq.push_back(0);
		deq.push_back(-7);

		std::cout << GREEN << "deq: " << RESET;
		for (int i = 0; i < 5; i++)
			std::cout << deq[i] << (i < 4 ? ", " : "\n\n");
		{
			int				value = -12;
			unsigned int	it = easyfind(deq, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = 14;
			unsigned int	it = easyfind(deq, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = 0;
			unsigned int	it = easyfind(deq, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int				value = -7;
			unsigned int	it = easyfind(deq, value);
			std::cout << "Value " << BLUE << value << RESET
				<< " find in index " << GREEN << it << ".\n" << RESET;
		}
		{
			int					value = -6;
			try
			{
				unsigned int	it = easyfind(deq, value);
				std::cout << it << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cerr << BLUE << value << RED << e.what() << std::endl << RESET;
			}
		}
	}
	return (0);
}
