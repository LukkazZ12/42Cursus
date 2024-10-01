/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:39 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:32:59 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

#include "ft_irc.hpp"

class	Message
{
	public:
		std::string					prefix;
		std::string					command;
		std::vector<std::string>	params;

		Message(void) {};
		~Message(void) {};
		Message(const Message& obj);
		Message& operator=(const Message& obj);

		void	parseMessage(std::string line);
		void	handleMessage(Client &client, Message &msg, std::vector<Client> &clients, std::vector<Channel> &channels);
};

#endif