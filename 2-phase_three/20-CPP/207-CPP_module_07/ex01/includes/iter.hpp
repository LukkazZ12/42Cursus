/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/07 16:07:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

template <typename T>
void	iter(T *array, size_t size, void f(T&, T&))
{
	if (size <= 1)
		std::cout << RED << "Invalid size.\n" << RESET;
	if (array)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1)
				f(array[i], array[i + 1]);
			else
				f(array[i], array[0]);
		}
	}
	else
		std::cout << RED << "Array is NULL.\n" << RESET;
	return ;
}

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
	return ;
}

#endif