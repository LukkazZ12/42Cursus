/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:26:33 by lucade-s          #+#    #+#             */
/*   Updated: 2023/11/03 19:41:17 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;

	std::cout << CLEAR_WINDOW << GREEN <<
		"\n--------------------------\n"
		"Welcome to your PhoneBook!\n"
		"--------------------------\n\n" << RESET;
	while(true)
	{
		std::cout << MAGENTA <<
			"Commands: ADD, SEARCH and EXIT\n\n" << CYAN <<
			"ADD: Save a new contact.\n"
			"SEARCH: Display a specific contact.\n"
			"EXIT: The program quits and the contacts are lost forever!\n"
			<< RESET;
		std::cout << YELLOW << "\nPlease, enter with a command: " << RESET;
		std::getline (std::cin, command);
		if(command == "ADD")
			phone_book.add();
		else if(command == "SEARCH")
			phone_book.search();
		else if(command == "EXIT")
		{
			std::cout << CLEAR_WINDOW << RED <<
			"\n--------------------------------------\n"
			"Your phone book has been lost forever!\n"
	 		"--------------------------------------\n\n";
			return(0);
		}
		else
			std::cout << CLEAR_WINDOW << RED <<
				"\nInvalid command. Try again.\n\n" << RESET;
	}
	return(0);
}
