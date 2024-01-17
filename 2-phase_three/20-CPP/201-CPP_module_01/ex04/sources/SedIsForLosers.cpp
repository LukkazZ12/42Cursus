/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:19:02 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/17 17:31:32 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

SedIsForLosers::SedIsForLosers(char **argv)
{
	std::string	output(argv[1]);

	this->s1 = argv[2];
	this->s2 = argv[3];
	this->inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << RED
			<< "It's not possible open the input file: " << argv[1] << std::endl << RESET;
		exit (1);
	}
	output += ".replace";
	char		*outputFilename = &output[0];
	this->outputFile.open(outputFilename);
	if (!outputFile.is_open())
	{
		std::cout << RED
			<< "It's not possible open the output file: " << outputFilename << std::endl << RESET;
		this->inputFile.close();
		exit (1);
	}
	std::cout << BLUE << "Created SedIsForLosers.\n" << RESET;
}

SedIsForLosers::~SedIsForLosers(void)
{
	this->inputFile.close();
	this->outputFile.close();
	std::cout << BLUE << "Destroed SedIsForLosers.\n" << RESET;
}

void	SedIsForLosers::replaceString(void)
{
	std::string	line;
	size_t		position;
	while (std::getline(this->inputFile, line))
	{
		if (strcmp(this->s1, this->s2) != 0)
		{
			position = line.find(this->s1);
			while (position != std::string::npos)
			{
				line.insert(position, this->s2);
				line.erase(position + std::strlen(this->s2), std::strlen(this->s1));
				position = line.find(this->s1);
			}
		}
		outputFile << line;
		outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return ;
}
