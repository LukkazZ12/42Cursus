/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:08 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 12:31:27 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message::Message(const Message& obj)
{
	*this = obj;
}

Message& Message::operator=(const Message& obj)
{
	this->prefix = obj.prefix;
	this->command = obj.command;
	this->params = obj.params;
	return (*this);
}

void	Message::parseMessage(std::string line)
{
	if (line.empty())
		throw std::runtime_error("Empty line.");
	if (line[0] == ':')
	{
		this->prefix = line.substr(1, line.find(' ') - 1);
		line = line.substr(line.find(' ') + 1, line.size() - 1);
	}
	this->params = Utils::split(line, " ");
	this->command = params.front();
	this->params.erase(this->params.begin());
	if (!params.empty() && params.back().find(':') != std::string::npos)
		params.back().erase(0, 1);
}

void	Message::handleMessage(Client &client, Message &msg, std::vector<Client> &clients, std::vector<Channel> &channels)
{
	CommandArgs	cArgs = CommandArgs(client, msg, clients, channels);
	if (cArgs.msg.params.size() > 15)
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Too many params"), cArgs.client);
		return ;
	}
	Commands::callFunction(cArgs);
}
