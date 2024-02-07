/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/07 16:16:43 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &fixed);

#endif