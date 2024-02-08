/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/08 20:29:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class Span
{
	private:
		std::vector<int>	integers;
		unsigned int		size;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &span);
		Span &operator=(const Span &span);
		~Span(void);
		void				addNumber(int number);
		int					shortestSpan(void);
		int					longestSpan(void);
		template <typename Iterator>
		void addNumbers(Iterator first, Iterator last)
		{
			while (first != last)
			{
				addNumber(*first);
				first++;
			}
		}
};

#endif