/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVITE.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:54:17 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 16:57:07 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	invite(CommandArgs cArgs)
{
	if (cArgs.msg.params.size() != 2)
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Wrong number of parameters"), cArgs.client);
		return ;
	}

	std::string	nickName = cArgs.msg.params[0];
	std::string	channelName = cArgs.msg.params[1];
	int			foundPosition = -1;

	for (size_t i = 0; i < cArgs.clients.size(); i++)
	{
		if (cArgs.clients[i] == nickName)
		{
			foundPosition = i;
			break ;
		}
	}
	if (foundPosition == -1)
	{
		cArgs.client.sendReplyToClient(ERR_NOSUCHNICK(cArgs.client.getNick(), nickName), cArgs.client);
		return ;
	}

	Client	recipient = cArgs.clients[foundPosition];
	std::vector<Channel>::iterator	itChannel = find(cArgs.channels.begin(), cArgs.channels.end(), channelName);
	if (itChannel == cArgs.channels.end())
	{
		cArgs.client.sendReplyToClient(ERR_NOSUCHCHANNEL(channelName), cArgs.client);
		return ;
	}
	if (!itChannel->isClientOnChannel(cArgs.client))
	{
		cArgs.client.sendReplyToClient(ERR_NOTONCHANNEL(channelName), cArgs.client);
		return ;
	}
	if (itChannel->getInviteOnly() && !itChannel->isOperator(cArgs.client))
	{
		cArgs.client.sendReplyToClient(ERR_CHANOPRIVSNEEDED(channelName), cArgs.client);
		return ;
	}
	if (itChannel->isClientOnChannel(recipient))
	{
		cArgs.client.sendReplyToClient(ERR_USERONCHANNEL(nickName, channelName), cArgs.client);
		return ;
	}
	recipient.sendReplyToClient(RPL_INVITEMSG(cArgs.client.getNick(), cArgs.client.getUser(), nickName, channelName), recipient);
	itChannel->addClientToInvited(recipient);
	cArgs.client.sendReplyToClient(RPL_INVITING(cArgs.client.getNick(), nickName, channelName), cArgs.client);
}
