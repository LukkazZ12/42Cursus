/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:10:08 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 18:38:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int						Server::_serverPort;
std::string				Server::_serverPassword;
int						Server::_socketFileDescriptor;
sockaddr_in				Server::_serverAddress;
std::vector<pollfd>		Server::_connectionsPollfds;
std::vector<Client>		Server::_clients;
std::vector<Channel>	Server::_channels;

Server::Server(const Server& obj)
{
	*this = obj;
}

Server&	Server::operator=(const Server& obj)
{
	this->_serverPort = obj._serverPort;
	this->_serverPassword = obj._serverPassword;
	this->_socketFileDescriptor = obj._socketFileDescriptor;
	this->_serverAddress = obj._serverAddress;
	this->_connectionsPollfds = obj._connectionsPollfds;
	this->_clients = obj._clients;
	this->_channels = obj._channels;
	return (*this);
}

std::string	Server::getServerPassword(void) const
{
	return (Server::_serverPassword);
}

std::vector<Client>	Server::getClients(void) const
{
	return (this->_clients);
}

std::vector<Channel>	Server::getChannels(void) const
{
	return (this->_channels);
}

void	Server::addChannel(Channel channel)
{
	this->_channels.push_back(channel);
}

void	Server::setPort(char *input)
{
	std::istringstream	toInt(input);
	int number;
	toInt >> number;

	if (number <= 0 || number > MAX_PORT)
		throw std::runtime_error("Invalid port number.");

	this->_serverPort = number;
}

void	Server::setPassword(char *input)
{
	if (!input[0])
		throw std::runtime_error("Invalid password.");
	for (int i = 0; input[i]; i++)
		if (!isprint(input[i]))
			throw std::runtime_error("Invalid password.");

	this->_serverPassword = input;
}

void	Server::createSocket(void)
{
	const int	ENABLE = 1;

	this->_socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_socketFileDescriptor < 0)
		throw std::runtime_error("Failed to create socket.");
	if (setsockopt(this->_socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR, &ENABLE, sizeof(int)) < 0)
		throw std::runtime_error("Failed to set socket options.");
	if (fcntl(this->_socketFileDescriptor, F_SETFL, O_NONBLOCK) == -1)
		throw std::runtime_error("Failed to set the non-blocking mode on socket file descriptor");
}

void	Server::defineServerAddress(void)
{
	std::memset(&_serverAddress, 0, sizeof(_serverAddress));
	this->_serverAddress.sin_family = AF_INET;
	this->_serverAddress.sin_port = htons(this->_serverPort);
	this->_serverAddress.sin_addr.s_addr = INADDR_ANY;
}

void	Server::bindSocket(void)
{
	if (bind(_socketFileDescriptor, (sockaddr *)&_serverAddress, sizeof(_serverAddress)) < 0)
		throw std::runtime_error("Failed to bind server file descriptor to socket.");
}

void	Server::listenForConnections(void)
{
	if (listen(_socketFileDescriptor, 1024) == -1)
		throw std::runtime_error("Failed to listen on socket.");
}

void	Server::configureTCP(void)
{
	createSocket();
	defineServerAddress();
	bindSocket();
	listenForConnections();
}

void Server::sigHandler(int)
{
	close(Server::_socketFileDescriptor);
	throw std::runtime_error("\nServer stopped by SIGINT");
}

void	Server::pollActiveConnections(void)
{
	if (poll(_connectionsPollfds.data(), _connectionsPollfds.size(), TIMEOUT_MS) < 0)
		throw std::runtime_error("Polling error.");
}

void	Server::acceptNewClients(void)
{
	if ((this->_connectionsPollfds[0].revents & POLLIN) == POLLIN)
	{
		sockaddr_in	newClientAddress;
		socklen_t	addressLength = sizeof(newClientAddress);
		int	newClientSocketDescriptor = accept(this->_socketFileDescriptor, (sockaddr *) &newClientAddress, &addressLength);

		if (newClientSocketDescriptor < 0)
			throw std::runtime_error("Failed to accept new client.");
		if (fcntl(newClientSocketDescriptor, F_SETFL, O_NONBLOCK) == -1)
			throw std::runtime_error("Failed to set client socket descriptor to non-blocking mode.");
		_connectionsPollfds.push_back((pollfd) {.fd = newClientSocketDescriptor, .events = POLLIN, .revents = 0});
		
		Client	newClient(newClientSocketDescriptor);
		newClient.setServerPass(this->getServerPassword());
		_clients.push_back(newClient);
	}
}

bool operator==(const pollfd &pollfd, const int &clientFd)
{
	return (pollfd.fd == clientFd);
}

bool	Server::detectedActivity(const int &clientFd)
{
	std::vector<pollfd>::iterator pollfd = std::find(_connectionsPollfds.begin(), _connectionsPollfds.end(), clientFd);
	return ((pollfd->revents & POLLIN) == POLLIN);
}

void	Server::disconnectClient(Client &client)
{
	for (size_t i = 0; i < this->_channels.size(); i++)
		this->_channels[i].removeClient(client);
	close(client.getFd());
	this->_connectionsPollfds.erase(find(this->_connectionsPollfds.begin(), this->_connectionsPollfds.end(), client.getFd()));
	std::vector<Client>::iterator	it;
	it = find(this->_clients.begin(), this->_clients.end(), client);
	this->_clients.erase(it);
}

void	Server::processClientsActivity(void)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		Client &client = _clients[i];
		if (detectedActivity(client.getFd()))
		{
			client.receiveData();
			client.pushToCommandQueue();

			std::queue<std::string>	&commands = client.getCommandsQueue();
			while(!commands.empty())
			{
				std::string	line = commands.front();
				commands.pop();

				Message	msg;
				msg.parseMessage(line);
				msg.handleMessage(client, msg, _clients, _channels);
			}
			if (client.getRemoveClient())
				disconnectClient(client);
		}
	}
}

void	Server::start(void)
{
	signal(SIGINT, &Server::sigHandler);

	_connectionsPollfds.push_back((pollfd) {.fd = this->_socketFileDescriptor, .events = POLLIN, .revents = 0});
	while (true)
	{
		pollActiveConnections();
		acceptNewClients();
		processClientsActivity();
	}
}
