/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:10:36 by byoshimo          #+#    #+#             */
/*   Updated: 2024/09/01 15:46:30 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# define MAX_PORT 65535
# define TIMEOUT_MS 1000
# define BUFFER_SIZE 512

# define CRLF std::string("\r\n")

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cctype>
#include <csignal>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>

class	Server;
class	Client;
class	Message;
class	Channel;
class	CommandArgs;
class	Commands;

#include "Client.hpp"
#include "Server.hpp"
#include "Message.hpp"
#include "Utils.hpp"
#include "Channel.hpp"
#include "CommandArgs.hpp"
#include "Commands.hpp"
#include "replies.hpp"

#endif