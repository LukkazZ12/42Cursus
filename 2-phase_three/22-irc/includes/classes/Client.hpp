/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:10:12 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 13:17:28 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "ft_irc.hpp"

class	Client
{
	private:
		int			_fd;
		bool		_removeClient;
		std::string	_data;
		std::string	_nick;
		std::string	_user;
		std::string	_realname;
		std::string	_pass;
		std::string	_serverPass;

		std::queue<std::string>	_commandsQueue;

	public:
		Client(void) {};
		Client(int socketDescriptor);
		Client(const Client &rhs);
		Client &operator=( const Client &rhs);
		~Client(void) {};

		int						getFd(void) const;
		bool					getRemoveClient(void) const;
		void					setRemoveClient(bool state);
		std::queue<std::string>	&getCommandsQueue(void);
		std::string				getNick(void) const;
		void					setNick(std::string nick);
		std::string				getUser(void) const;
		void					setUser(std::string user);
		std::string				getRealname(void) const;
		void					setRealname(std::string realname);
		std::string				getPass(void) const;
		void					setPass(std::string pass);
		std::string				getServerPass(void) const;
		void					setServerPass(std::string pass);

		bool					isAuthenticated() const;

		bool	operator==(const Client& obj);
		bool	operator==(const std::string& str);

		void	receiveData(void);
		void	pushToCommandQueue(void);
		void	sendReplyToClient(std::string reply, Client client);
		void	sendReplyToBroadcastList(std::string reply, std::vector<Client> broadcastList);
};

#endif