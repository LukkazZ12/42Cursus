/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:58:42 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/15 18:46:11 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(void) : _userLimit(1024),_i(false), _t(false), _k(false), _l(false) {}

Channel::Channel(std::string &name) : _name(name), _userLimit(1024), _i(false), _t(false), _k(false), _l(false) {}

Channel::Channel(const Channel& obj)
{
	*this = obj;
}

Channel&	Channel::operator=(const Channel &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_topic = obj.getTopic();
		this->_key = obj.getKey();
		this->_clients = obj.getClients();
		this->_operators = obj.getOperators();
		this->_userLimit = obj.getUserLimit();
		this->_i = obj.getInviteOnly();
		this->_t = obj.getTopicOPOnly();
		this->_k = obj._k;
		this->_l = obj._l;
	}
	return (*this);
}

std::string	Channel::getName(void) const
{
	return (this->_name);
}

void	Channel::setName(std::string name)
{
	this->_name = name;
}

std::string	Channel::getTopic(void) const
{
	return (this->_topic);
}

void	Channel::setTopic(std::string topic)
{
	this->_topic = topic;
}

std::string	Channel::getKey(void) const
{
	return (this->_key);
}

void	Channel::setKey(std::string key)
{
	this->_key = key;
}

std::vector<Client>	Channel::getClients(void) const
{
	return (this->_clients);
}

void	Channel::setClients(std::vector<Client> clients)
{
	this->_clients = clients;
}

std::vector<Client>	Channel::getOperators(void) const
{
	return (this->_operators);
}

void	Channel::addOperator(Client	&client)
{
	this->_operators.push_back(client);
}

void	Channel::removeOperator(Client &client)
{
	this->_operators.erase(find(this->_operators.begin(), this->_operators.end(), client));
}

size_t	Channel::getUserLimit(void) const
{
	return (this->_userLimit);
}

void	Channel::setUserLimit(size_t limit)
{
	this->_l = true;
	this->_userLimit = limit;
}

bool	Channel::getInviteOnly(void) const
{
	return (this->_i);
}

void	Channel::setInviteOnly(bool action)
{
	this->_i = action;
}

bool	Channel::getTopicOPOnly(void) const
{
	return (this->_t);
}

void	Channel::setTopicOPOnly(bool action)
{
	this->_t = action;
}

bool	Channel::isClientOnChannel(const Client &client)
{
	std::vector<Client>::iterator	it;
	it = find(this->_clients.begin(), this->_clients.end(), client);
	if (it == this->_clients.end())
		return (false);
	return (true);
}

bool	Channel::isOperator(const Client &client)
{
	std::vector<Client>::iterator	it;
	it = find(this->_operators.begin(), this->_operators.end(), client);
	if (it == this->_operators.end())
		return (false);
	return (true);
}

void	Channel::addClient(Client &client)
{
	this->_clients.push_back(client);
}

void	Channel::removeClient(Client &client)
{
	std::vector<Client>::iterator	itClient = find(this->_clients.begin(), this->_clients.end(), client);
	std::vector<Client>::iterator	itOperator = find(this->_operators.begin(), this->_operators.end(), client);

	if (itClient != this->_clients.end())
		this->_clients.erase(itClient);
	if (itOperator != this->_operators.end())
		this->_operators.erase(itOperator);
}

void	Channel::removeKey(void)
{
	this->_k = false;
	this->_key = "";
}

void	Channel::removeUserLimit(void)
{
	this->_l = false;
	this->_userLimit = -1;
}

std::string	Channel::getChannelUsers(void)
{
	std::string	users;
	for (size_t i = 0; i < this->_clients.size(); i++)
		users += this->_clients[i].getUser() + " ";
	return (users);
}

std::string	Channel::getModes(void)
{
	std::string	modes = "+";
	if (this->_i)
		modes += "i";
	if (this->_t)
		modes += "t";
	if (this->_k)
		modes += "k";
	if (this->_l)
		modes += "l";
	if (this->_k || this->_l)
	{
		modes += " ";
		if (this->_k)
			if (!this->_key.empty())
				modes += this->_key + " ";
		if (this->_l)
		{
			std::ostringstream oss;
			oss << this->_userLimit;
			modes += oss.str();
		}
	}
	return (modes);
}

void	Channel::addClientToInvited(Client &client)
{
	this->_invitedClients.push_back(client);
}

bool	Channel::isClientInvited(Client &client)
{
	std::vector<Client>::iterator	it;
	it = find(this->_invitedClients.begin(), this->_invitedClients.end(), client);
	if (it == this->_invitedClients.end())
		return (false);
	return (true);
}

void	Channel::removeClientFromInvited(Client &client)
{
	std::vector<Client>::iterator	it;
	it = find(this->_invitedClients.begin(), this->_invitedClients.end(), client);
	if (it != this->_invitedClients.end())
		this->_invitedClients.erase(it);
}

bool Channel::operator==(const std::string& str)
{
	return (this->_name == str);
}
