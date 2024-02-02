/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 20:58:51 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <cstdlib>
# include "Data.hpp"

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define CLEAR_WINDOW	"\033[2J\033[1;1H"

class Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);
		~Serializer(void);
};

#endif