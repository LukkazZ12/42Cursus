/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:44:47 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:46:16 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	kick(CommandArgs cArgs)
{
	if (cArgs.msg.params.size() < 2 || cArgs.msg.params.size() > 3)
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Wrong number of parameters"), cArgs.client);
		return ;
	}
	std::string	message;
	if (cArgs.msg.params.size() == 3)
		message = cArgs.msg.params[2];
	else
		message = "User kicked from channel";
	std::vector<std::string>	channels = Utils::split(cArgs.msg.params[0], ",");
	std::vector<std::string>	clients = Utils::split(cArgs.msg.params[1], ",");
	if (channels.size() != 1 && channels.size() != clients.size())
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Different numbers of channels and clients given"), cArgs.client);
		return ;
	}
	for (size_t i = 0; i < channels.size(); i++)
	{
		std::string	channelName = channels[i];
		std::vector<Channel>::iterator	itChannel = find(cArgs.channels.begin(), cArgs.channels.end(), channelName);
		if (itChannel == cArgs.channels.end())
		{
			cArgs.client.sendReplyToClient(ERR_NOSUCHCHANNEL(channelName), cArgs.client);
			continue ;
		}
		if (!itChannel->isClientOnChannel(cArgs.client))
		{
			cArgs.client.sendReplyToClient(ERR_NOTONCHANNEL(channelName), cArgs.client);
			continue ;
		}
		if (!itChannel->isOperator(cArgs.client))
		{
			cArgs.client.sendReplyToClient(ERR_CHANOPRIVSNEEDED(channelName), cArgs.client);
			continue ;
		}
		for (size_t j = 0; j < clients.size(); j++)
		{
			if (channels.size() != 1)
				j = i;
			std::vector<Client>::iterator	itClients = find(itChannel->getClients().begin(), itChannel->getClients().end(), clients[j]);
			if (itClients == itChannel->getClients().end())
			{
				cArgs.client.sendReplyToClient(ERR_USERNOTINCHANNEL(clients[j], channelName), cArgs.client);
				continue ;
			}
			if (*itClients == cArgs.client)
			{
				cArgs.client.sendReplyToClient(ERR_CANNOTKICKYOURSELF(cArgs.client.getNick()), cArgs.client);
				continue ;
			}
			cArgs.client.sendReplyToBroadcastList(KICK(cArgs.client.getNick(), cArgs.client.getUser(), channelName, message), itChannel->getClients());
			itChannel->removeClient(*itClients);
			if (channels.size() != 1)
				break ;
		}
	}
}
