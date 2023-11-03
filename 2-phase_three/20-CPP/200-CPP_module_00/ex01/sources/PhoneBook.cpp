/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:01:34 by lucade-s          #+#    #+#             */
/*   Updated: 2023/11/03 19:39:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->number_of_contacts = 0;
	this->index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	std::string	temp_buffer;
	Contact		new_contact;

	std::cout << CLEAR_WINDOW << CYAN << "\nAdd Contact infos\n\n" << RESET;
	temp_buffer = "";
	while (temp_buffer == "")
	{
		std::cout << "First name: ";
		std::getline (std::cin, temp_buffer);
		if (temp_buffer == "")
			std::cout << RED << "Invalid first name\n\n" << RESET;
	}
	new_contact.set_first_name(temp_buffer);
	temp_buffer = "";
	while (temp_buffer == "")
	{
		std::cout << "Last Name: ";
		std::getline (std::cin, temp_buffer);
		if (temp_buffer == "")
			std::cout << RED << "Invalid last name\n\n" << RESET;
	}
	new_contact.set_last_name(temp_buffer);
	temp_buffer = "";
	while (temp_buffer == "")
	{
		std::cout << "Nickname: ";
		std::getline (std::cin, temp_buffer);
		if (temp_buffer == "")
			std::cout << RED << "Invalid nickname\n\n" << RESET;
	}
	new_contact.set_nickname(temp_buffer);
	temp_buffer = "";
	while (temp_buffer == "" || temp_buffer.find_first_not_of("0123456789()-") \
		!= std::string::npos)
	{
		std::cout << "Phone number: ";
		std::getline (std::cin, temp_buffer);
		if (temp_buffer == "" || temp_buffer.find_first_not_of("0123456789()-") \
			!= std::string::npos)
			std::cout << RED << "Invalid phone book. Only numbers, '(', ')' and '-'.\n\n" << RESET;
	}
	new_contact.set_phone_number(temp_buffer);
	temp_buffer = "";
	while (temp_buffer == "")
	{
		std::cout << "Darkest secret: ";
		std::getline (std::cin, temp_buffer);
		if (temp_buffer == "")
			std::cout << RED << "Invalid darkest secret\n\n" << RESET;
	}
	new_contact.set_darkest_secret(temp_buffer);
	contacts[this->index] = new_contact;
	this->index++;
	if (this->number_of_contacts < 8)
		this->number_of_contacts++;
	if (this->index == 8)
		this->index = 0;
	std::cout << CLEAR_WINDOW << GREEN << "\nContact added.\n\n" << RESET;
	return ;
}

void	PhoneBook::search(void)
{
	int			index;
	std::string	id;
	
	if (!this->number_of_contacts)
	{
		std::cout << CLEAR_WINDOW << RED << "\nPhone book is empty.\n\n" << RESET;
		return ;
	}
	std::cout << CLEAR_WINDOW << GREEN
		<< "\n-----------------------------------------------------------------"
		<< "\n                            PHONE BOOK                           "
		<< "\n-----------------------------------------------------------------"
		<< "\n|             ID|     First Name|      Last Name|       Nickname|\n"
		<< RESET;
	for (int i = 0; i < this->number_of_contacts; i++)
		this->print_info(this->contacts[i], i);
	index = -1;
	id = "";
	while (index < 0 || index >= this->number_of_contacts || id == "" \
		|| id.find_first_not_of("01234567") != std::string::npos)
	{
		std::cout << CYAN << "\nInsert ID to search (0 - 7): " << RESET;
		std::getline (std::cin, id);
		std::stringstream	str_to_int;
		str_to_int << id;
		str_to_int >> index;
		if (index < 0 || index >= this->number_of_contacts || id == "" \
			|| id.find_first_not_of("01234567") != std::string::npos)
			std::cout << RED << "\nInvalid ID\n" << RESET;
		else
		{
			std::cout << CLEAR_WINDOW << CYAN << "Contact " << index << ":" << std::endl << RESET;;
			this->print_contact(this->contacts[index]);
		}
	}
}

void	PhoneBook::print_info(Contact contact, int index)
{
	Contact	format = contact;

	if (format.get_first_name().length() > 15)
	{
		format.set_first_name(format.get_first_name().substr(0, 14) + '.');
	}
	if (format.get_last_name().length() > 15)
	{
		format.set_last_name(format.get_last_name().substr(0, 14) + '.');
	}
	if (format.get_nickname().length() > 15)
	{
		format.set_nickname(format.get_nickname().substr(0, 14) + '.');
	}
	if (format.get_phone_number().length() > 15)
	{
		format.set_phone_number(format.get_phone_number().substr(0, 14) + '.');
	}
	if (format.get_darkest_secret().length() > 15)
	{
		format.set_darkest_secret(format.get_darkest_secret().substr(0, 14) + '.');
	}
	std::cout << "|" << std::setw(15) << index; 
	std::cout << "|" << std::setw(15) << format.get_first_name();
	std::cout << "|" << std::setw(15) << format.get_last_name();
	std::cout << "|" << std::setw(15) << format.get_nickname() << "|\n";
}

void	PhoneBook::print_contact(Contact contact)
{
	std::cout << "\nFirst name: " << contact.get_first_name();
	std::cout << "\nLast name: " << contact.get_last_name();
	std::cout << "\nNickname: " << contact.get_nickname();
	std::cout << "\nPhone number: " << contact.get_phone_number();
	std::cout << "\nDarkest secret: " << contact.get_darkest_secret();
	std::cout << std::endl << std::endl;
}
