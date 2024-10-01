/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:16:32 by byoshimo          #+#    #+#             */
/*   Updated: 2024/07/24 21:32:42 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "ft_irc.hpp"

class	Utils
{
	public:
		Utils(void) {};
		~Utils(void) {};

		static std::vector<std::string>	split(std::string str, std::string delimiter);
};

#endif