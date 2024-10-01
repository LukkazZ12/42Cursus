/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PART.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:20:42 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:47:37 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	part(CommandArgs cArgs)
{
	if (cArgs.msg.params.size() < 1 || cArgs.msg.params.size() > 2)
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Wrong number of parameters"), cArgs.client);
		return ;
	}
	
	std::vector<std::string>	channels = Utils::split(cArgs.msg.params[0], ",");
	std::string					message;
	if (cArgs.msg.params.size() == 2)
		message = cArgs.msg.params[1];
	else
		message = "No message";
	for (size_t i = 0; i < channels.size(); i++)
	{
		std::string	channelName = channels[i];
		std::vector<Channel>::iterator	it = find(cArgs.channels.begin(), cArgs.channels.end(), channelName);
		if (it == cArgs.channels.end())
		{
			cArgs.client.sendReplyToClient(ERR_NOSUCHCHANNEL(channelName), cArgs.client);
			continue ;
		}
		if (!it->isClientOnChannel(cArgs.client))
		{
			cArgs.client.sendReplyToClient(ERR_NOTONCHANNEL(channelName), cArgs.client);
			continue ;
		}
		it->removeClient(cArgs.client);
		if (it->getClients().empty())
			cArgs.channels.erase(it);
		else
			cArgs.client.sendReplyToBroadcastList(PART(cArgs.client.getNick(), cArgs.client.getUser(), channelName, message), it->getClients());
	}
}
