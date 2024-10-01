/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:10:30 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 17:14:38 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "ft_irc.hpp"

class	Server
{
	private:
		static int						_serverPort;
		static std::string				_serverPassword;
		static int						_socketFileDescriptor;
		static sockaddr_in				_serverAddress;
		static std::vector<pollfd>		_connectionsPollfds;
		static std::vector<Client>		_clients;
		static std::vector<Channel>		_channels;

		void		createSocket(void);
		void		defineServerAddress(void);
		void		bindSocket(void);
		void		listenForConnections(void);
		static void	sigHandler(int);
		void		pollActiveConnections(void);
		void		acceptNewClients(void);
		void		processClientsActivity(void);
		bool		detectedActivity(const int &clientFd);
		void		disconnectClient(Client &client);

	public:
		Server(void) {};
		~Server(void) {};
		Server(const Server& obj);
		Server&	operator=(const Server& obj);

		void	setPort(char *input);
		void	setPassword(char *input);
		void	configureTCP(void);
		void	start(void);

		std::string				getServerPassword(void) const;
		std::vector<Client>		getClients(void) const;
		std::vector<Channel>	getChannels(void) const;
		void					addChannel(Channel channel);
};

#endif