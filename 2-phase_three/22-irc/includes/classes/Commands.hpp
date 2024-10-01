/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:44 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 11:48:56 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "ft_irc.hpp"

class	Commands
{
	public:
		typedef void (*funcPtr)(CommandArgs);

		static void	populateMap(void);
		static void	callFunction(CommandArgs &cArgs);

		Commands(void) {}
		~Commands(void) {}

	private:
		static std::map<std::string, funcPtr>	_commands;
};

void	user(CommandArgs cArgs);
void	nick(CommandArgs cArgs);
void	pass(CommandArgs cArgs);
void	quit(CommandArgs cArgs);
void	join(CommandArgs cArgs);
void	part(CommandArgs cArgs);
void	privmsg(CommandArgs cArgs);
void	kick(CommandArgs cArgs);
void	invite(CommandArgs cArgs);
void	topic(CommandArgs cArgs);
void	mode(CommandArgs cArgs);

#endif