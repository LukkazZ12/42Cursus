/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:10:19 by byoshimo          #+#    #+#             */
/*   Updated: 2024/06/29 19:10:26 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 3)
			throw std::runtime_error("Error: wrong number of arguments!\nUsage: ./ircserv <port> <password>");

		Commands::populateMap();
		Server	server;
		server.setPort(argv[1]);
		server.setPassword(argv[2]);
		server.configureTCP();
		server.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
