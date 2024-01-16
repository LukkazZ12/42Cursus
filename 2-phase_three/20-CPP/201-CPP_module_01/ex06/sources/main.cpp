/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:41:33 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/16 18:53:55 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << YELLOW <<
			"Usage: ./harlFilter <level> (DEBUG, INFO, WARNING, ERROR)\n" << RESET;
		return (1);
	}
	Harl	harl;

	harl.complain(argv[1]);
	return (0);
}
