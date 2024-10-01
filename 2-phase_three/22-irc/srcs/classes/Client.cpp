/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:09:58 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 13:32:34 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int socketDescriptor)
{
	this->_fd = socketDescriptor;
	this->_removeClient = false;
}

Client::Client(const Client &rhs) {
	*this = rhs;
}

Client &Client::operator=(const Client &obj) {
	if (&obj != this)
	{
		this->_fd = obj._fd;
		this->_removeClient = obj._removeClient;
		this->_data = obj._data;
		this->_nick = obj._nick;
		this->_user = obj._user;
		this->_realname = obj._realname;
		this->_pass = obj._pass;
		this->_serverPass = obj._serverPass;
	}
	return (*this);
}

int Client::getFd(void) const
{
	return (this->_fd);
}

bool	Client::getRemoveClient(void) const
{
	return (this->_removeClient);
}

void	Client::setRemoveClient(bool state)
{
	this->_removeClient = state;
}

std::queue<std::string>	&Client::getCommandsQueue(void)
{
	return (this->_commandsQueue);
}

std::string	Client::getNick(void) const
{
	return (this->_nick);
}

void	Client::setNick(std::string nick)
{
	this->_nick = nick;
}

std::string	Client::getUser(void) const
{
	return (this->_user);
}

void	Client::setUser(std::string user)
{
	this->_user = user;
}

std::string	Client::getRealname(void) const
{
	return (this->_realname);
}

void	Client::setRealname(std::string realname)
{
	this->_realname = realname;
}

std::string	Client::getPass(void) const
{
	return (this->_pass);
}

void	Client::setPass(std::string pass)
{
	this->_pass = pass;
}

std::string	Client::getServerPass(void) const
{
	return (this->_serverPass);
}

void	Client::setServerPass(std::string pass)
{
	this->_serverPass = pass;
}

bool	Client::isAuthenticated() const
{
	if (this->_user.empty() || this->_nick.empty() || this->_pass.empty())
		return false;
	return true;
}

bool Client::operator==(const Client& obj)
{
	return (this->_user == obj._user);
}

bool Client::operator==(const std::string& str)
{
	return (this->_user == str || this->_nick == str);
}

void	Client::receiveData(void)
{
	char	buff[BUFFER_SIZE];
	std::memset(buff, 0, BUFFER_SIZE);

	long	nbytes = recv(this->getFd(), buff, BUFFER_SIZE, 0);
	if (nbytes == 0)
		this->setRemoveClient(true);
	else
		this->_data.append(buff, nbytes);
}

void	Client::pushToCommandQueue(void)
{
	if (this->_data.empty())
		return ;
	std::vector<std::string>	commands = Utils::split(this->_data, "\r\n");
	if (this->_data.size() < 2 || this->_data[this->_data.size() - 2] != '\r' || this->_data[this->_data.size() - 1] != '\n')
	{
		this->_data = commands.back();
		commands.pop_back();
	}
	else
		this->_data.clear();
	for (std::vector<std::string>::iterator command = commands.begin(); command != commands.end(); command++)
		this->_commandsQueue.push(*command);
}

void	Client::sendReplyToClient(std::string reply, Client client)
{
	if (reply.empty())
		return ;
	if (send(client.getFd(), reply.c_str(), reply.length(), 0) == -1)
		std::cerr << "Failed to send message to client." << std::endl;
}

void	Client::sendReplyToBroadcastList(std::string reply, std::vector<Client> broadcastList)
{
	if (broadcastList.empty())
		return ;
	std::vector<Client>::iterator	it = broadcastList.begin();
	for (; it != broadcastList.end(); it++)
		sendReplyToClient(reply, *it);
}
