/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:01 by lucade-s          #+#    #+#             */
/*   Updated: 2024/02/01 19:43:21 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "Serializer.hpp"

class Data
{
	private:
		int		value;
	public:
		Data(void);
		Data(int value);
		Data(const Data &data);
		Data &operator=(const Data &data);
		~Data(void);
		int		getValue(void) const;
		void	setValue(int value);
};

#endif