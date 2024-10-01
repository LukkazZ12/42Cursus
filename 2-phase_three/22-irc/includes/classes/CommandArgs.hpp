/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandArgs.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:50 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:23:33 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_ARGS_HPP
# define COMMAND_ARGS_HPP

#include "ft_irc.hpp"

class	CommandArgs
{
	public:
		Client					&client;
		Message					&msg;
		// Server					&server;
		std::vector<Client>		&clients;
		std::vector<Channel>	&channels;

		CommandArgs(Client &client, Message &msg, std::vector<Client> &clients, std::vector<Channel> &channels) \
			: client(client), msg(msg), clients(clients), channels(channels) {}
		~CommandArgs(void) {}
};

#endif