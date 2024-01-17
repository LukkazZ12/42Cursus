/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:01:34 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:28:06 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << YELLOW <<
			"Usage: ./sedIsForLosers <filename> <s1> <s2>\n" << RESET;
		return (1);
	}
	SedIsForLosers	sedIsForLosers(argv);

	sedIsForLosers.replaceString();
	return (0);
}
