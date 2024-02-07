/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/07 15:47:16 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	arraySize;
	public:
		Array(void)
		{
			this->array = NULL;
			this->arraySize = 0;
		};
		Array(unsigned int size)
		{
			if (!size)
			{
				this->array = NULL;
				this->arraySize = 0;
			}
			else
			{
				this->array = new T[size];
				this->arraySize = size;
			}
		};
		Array(const Array &array)
		{
			this->array = NULL;
			this->arraySize = 0;
			*this = array;
		}
		Array	&operator=(const Array &array)
		{
			if (this->array)
				delete[] this->array;
			new(this) Array(array.arraySize);
			for (unsigned int i = 0; i < array.arraySize; i++)
				this->array[i] = array.array[i];
			return (*this);
		}
		~Array()
		{
			if (this->array)
				delete[] this->array;
			this->arraySize = 0;
			this->array = NULL;
		};
		T	&operator[](int index)
		{
			if (index < 0 || index >= (int)this->arraySize)
				throw (std::out_of_range("Error: Index out of range."));
			return (this->array[index]);
		}
		unsigned int	size(void)
		{
			return (this->arraySize);
		}
		T	*getArray(void) const
		{
			return (this->array);
		}
};

#endif