/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/09 16:10:21 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &mutant)
		{
			*this = mutant;
			return ;
		}
		MutantStack	&operator=(const MutantStack &mutant)
		{
			if (this != &mutant)
				std::stack<T>::operator=(mutant);
			return (*this);
		}
		~MutantStack(void) {};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin(void) const
		{
			return (this->c.cbegin());
		}
		const_iterator	end(void) const
		{
			return (this->c.cend());
		}
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void)
		{
			return std::stack<T>::c.rbegin();
		};
		reverse_iterator	rend(void)
		{
			return std::stack<T>::c.rend();
		};
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin(void) const
		{
			return std::stack<T>::c.rbegin();
		};
		const_reverse_iterator	rend(void) const
		{
			return std::stack<T>::c.rend();
		};
};

#endif