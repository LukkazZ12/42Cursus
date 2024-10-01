/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:24 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 17:01:43 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

# define FTIRC std::string(":ircserv")
# define CRLF std::string("\r\n")

# define RPL_WELCOME(nick, user)						(FTIRC + " 001 " + user + " :Welcome to the Internet Relay Chat " + nick + "!" + user + "@*" + CRLF)
# define RPL_CHANNELMODEIS(nick, channel, mode, params)	(FTIRC + " 324 " + nick + " " + channel + " " + mode + " " + params + CRLF)
# define RPL_NOTOPIC(nick, channel)						(FTIRC + " 331 " + nick + " " + channel + " :No topic is set" + CRLF)
# define RPL_TOPIC(nick, channel, topic)				(FTIRC + " 332 " + nick + " " + channel + " :" + topic + CRLF)
# define RPL_INVITING(nick, recipient, channel)			(FTIRC + " 341 " + nick + " " + recipient + " :" + channel + CRLF)
# define RPL_NAMREPLY(nick, channel, names)				(FTIRC + " 353 " + nick + " = " + channel + " :" + names + CRLF)
# define RPL_ENDOFNAMES(nick, channel)					(FTIRC + " 366 " + nick + " " + channel + " :End of NAMES list" + CRLF)

# define ERR_NOSUCHNICK(nick, recipient)				(FTIRC + " 401 * " + nick + " " + recipient + " :No such nick/channel" + CRLF)
# define ERR_NOSUCHCHANNEL(channel)						(FTIRC + " 403 * " + channel + ":No such channel" + CRLF)
# define ERR_CANNOTSENDTOCHAN(nick, channel)			(FTIRC + " 404 * " + nick + " " + channel + " :Cannot send to channel" + CRLF)
# define ERR_NORECIPIENT(nick, command)					(FTIRC + " 411 * " + nick + " :No recipient given (" + command + ")" + CRLF)
# define ERR_NOTEXTTOSEND(nick)							(FTIRC + " 412 * " + nick + " :No text to send" + CRLF)
# define ERR_NONICKNAMEGIVEN()							(FTIRC + " 431 :No nickname given" + CRLF)
# define ERR_ERRONEUSNICKNAME(nick)						(FTIRC + " 432 * " + nick + " :Nickname is invalid" + CRLF)
# define ERR_NICKNAMEINUSE(nick)						(FTIRC + " 433 * " + nick + " :Nickname is already in use" + CRLF)
# define ERR_USERNOTINCHANNEL(nick, channel)			(FTIRC + " 441 * " + nick + " " + channel + ": They aren't on that channel" + CRLF)
# define ERR_NOTONCHANNEL(channel)						(FTIRC + " 442 * " + channel + " :Client not on channel" + CRLF)
# define ERR_USERONCHANNEL(user, channel)				(FTIRC + " 443 * " + user + " " + channel + " :is already on channel" + CRLF)
# define ERR_NOTREGISTERED(nick)						(FTIRC + " 451 * " + nick + " :You have not registered" + CRLF)
# define ERR_NEEDMOREPARAMS(command, reason)			(FTIRC + " 461 * " + command + " :" + reason + CRLF)
# define ERR_ALREADYREGISTRED(user)						(FTIRC + " 462 * " + user + ":User already registered" + CRLF)
# define ERR_PASSWDMISMATCH()							(FTIRC + " 464 * :Password incorrect" + CRLF)
# define ERR_SETKEY(channel)							(FTIRC + " 467 * :Channel key already set" + CRLF)
# define ERR_CHANNELISFULL(channel)						(FTIRC + " 471 * " + channel + ":Cannot join channel (Channel is full)" + CRLF)
# define ERR_UNKNOWNMODE(mode, channel)					(FTIRC + " 472 * " + mode + " :is unknown mode char to me for " + channel + CRLF)
# define ERR_INVITEONLYCHAN(channel)					(FTIRC + " 473 * " + channel + ":Cannot join channel (Invite only channel)" + CRLF)
# define ERR_BADCHANNELKEY(channel)						(FTIRC + " 475 * " + channel + ":Cannot join channel (Incorrect password)" + CRLF)
# define ERR_CHANOPRIVSNEEDED(channel)					(FTIRC + " 482 * " + channel + ":You're not channel operator" + CRLF)

# define JOIN(nick, user, channel)						(":" + nick + "!" + user + "@* JOIN " + channel + CRLF)
# define QUIT(nick, user)								(":" + nick + "!" + user + "@* QUIT : User has quit IRC" + CRLF)
# define PART(nick, user, channel, message)				(":" + nick + "!" + user + "@* PART :" + channel + " :" + message + CRLF)
# define PRIVMSG(nick, user, recipient, message)		(":" + nick + "!" + user + "@* PRIVMSG " + recipient + " :" + message + CRLF)
# define KICK(nick, user, channel, message)				(":" + nick + "!" + user + "@* KICK " + channel + " :" + message + CRLF)
# define ERR_CANNOTKICKYOURSELF(nick)					(FTIRC + " " + nick + " :Cannot kick yourself" + CRLF)
# define RPL_INVITEMSG(nick, user, recipient, channel)	(":" + nick + "!" + user + "@* INVITE " + recipient + " :" + channel + CRLF)
# define TOPICMSG(nick, user, channel, topic)			(":" + nick + "!" + user + "@* TOPIC " + channel + " :" + topic + CRLF)
# define INVALIDCMD(nick)								(FTIRC + " " + nick + " :Invalid command" + CRLF)

#endif