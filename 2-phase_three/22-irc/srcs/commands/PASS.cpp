/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PASS.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:15:18 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 13:26:53 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	pass(CommandArgs cArgs)
{
	if (cArgs.msg.params.size() != 1)
	{
		cArgs.client.sendReplyToClient(ERR_NEEDMOREPARAMS(cArgs.msg.command, "Wrong number of parameters"), cArgs.client);
		return ;
	}
	if (!cArgs.client.getPass().empty())
	{
		cArgs.client.sendReplyToClient(ERR_ALREADYREGISTRED(cArgs.client.getUser()), cArgs.client);
		return ;
	}
	cArgs.client.setPass(cArgs.msg.params[0]);
	if (cArgs.client.getPass() != cArgs.client.getServerPass())
	{
		cArgs.client.setPass("");
		cArgs.client.sendReplyToClient(ERR_PASSWDMISMATCH(), cArgs.client);
		return ;
	}
	if (cArgs.client.isAuthenticated())
		cArgs.client.sendReplyToClient(RPL_WELCOME(cArgs.client.getNick(), cArgs.client.getUser()), cArgs.client);
}
