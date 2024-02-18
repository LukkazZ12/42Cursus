/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:17:14 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/17 18:15:00 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << RED << "Invalid arguments.\n" << RESET;
		std::cerr << GREEN << "Usage: ./PMergeMe [parameters]\n" << RESET;
		return (1);
	}

	PMergeMe	merge;
	try
	{
		merge.FordJohnson(argc, argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what()<< RESET << std::endl;
	}
	return (0);
}
