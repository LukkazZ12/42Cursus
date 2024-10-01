/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QUIT.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:15:23 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:49:55 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	quit(CommandArgs cArgs)
{
	cArgs.client.setRemoveClient(true);
	cArgs.client.sendReplyToBroadcastList(QUIT(cArgs.client.getNick() ,cArgs.client.getUser()), cArgs.clients);
}
