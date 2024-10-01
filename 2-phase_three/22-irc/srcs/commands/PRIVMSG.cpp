/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRIVMSG.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:44:58 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:48:12 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	privmsg(CommandArgs cArgs)
{
	if (cArgs.msg.params.size() < 1)
	{
		cArgs.client.sendReplyToClient(ERR_NORECIPIENT(cArgs.client.getNick(), "PRIVMSG"), cArgs.client);
		return ;
	}
	if (cArgs.msg.params.size() < 2)
	{
		cArgs.client.sendReplyToClient(ERR_NOTEXTTOSEND(cArgs.client.getNick()), cArgs.client);
		return ;
	}
	
	std::string	recipient = cArgs.msg.params[0];
	if (recipient[0] == '#' || recipient[0] == '&')
	{
		std::vector<Channel>::iterator	itChannel;
		itChannel = find(cArgs.channels.begin(), cArgs.channels.end(), recipient);
		if (itChannel != cArgs.channels.end())
		{
			if (!itChannel->isClientOnChannel(cArgs.client))
			{
				cArgs.client.sendReplyToClient(ERR_CANNOTSENDTOCHAN(cArgs.client.getNick(), itChannel->getName()), cArgs.client);
				return ;
			}
			std::vector<Client>				broadcastList;
			std::vector<Client>::iterator	itClient;
			broadcastList = itChannel->getClients();
			itClient = find(broadcastList.begin(), broadcastList.end(), cArgs.client);
			broadcastList.erase(itClient);
			cArgs.client.sendReplyToBroadcastList(PRIVMSG(cArgs.client.getNick(), cArgs.client.getUser(), recipient, cArgs.msg.params[1]), broadcastList);
		}
		else
			cArgs.client.sendReplyToClient(ERR_NOSUCHNICK(cArgs.client.getNick(), recipient), cArgs.client);
	}
	else
	{
		std::vector<Client>::iterator	itClient;
		itClient = find(cArgs.clients.begin(), cArgs.clients.end(), recipient);
		if (cArgs.clients.empty() || itClient == cArgs.clients.end())
		{
			cArgs.client.sendReplyToClient(ERR_NOSUCHNICK(cArgs.client.getNick(), recipient), cArgs.client);
			return ;
		}
		cArgs.client.sendReplyToClient(PRIVMSG(cArgs.client.getNick(), cArgs.client.getUser(), recipient, cArgs.msg.params[1]), *itClient);
	}
}
