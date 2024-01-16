/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:01:34 by lucade-s          #+#    #+#             */
/*   Updated: 2024/01/16 20:39:07 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceString(const std::string &filename, const std::string &s1, const std::string &s2)
{
	// Abre o arquivo de entrada
	std::ifstream inputFile(filename);
		
	// Verifica se o arquivo de entrada foi aberto com sucesso
	if (!inputFile.is_open()) {
		std::cerr << "Erro ao abrir o arquivo de entrada: " << filename << std::endl;
		return;
	}

	// Cria o nome do arquivo de saída
	std::string outputFilename = filename + ".replace";

	// Abre o arquivo de saída
	std::ofstream outputFile(outputFilename);

	// Verifica se o arquivo de saída foi aberto com sucesso
	if (!outputFile.is_open()) {
		std::cerr << "Erro ao abrir o arquivo de saída: " << outputFilename << std::endl;
		return;
	}

	// Processa cada linha do arquivo de entrada
	std::string line;
	while (std::getline(inputFile, line)) {
		// Substitui todas as ocorrências de s1 por s2 na linha
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}

		// Escreve a linha modificada no arquivo de saída
		outputFile << line << '\n';
	}

	// Fecha os arquivos
	inputFile.close();
	outputFile.close();

	std::cout << "Substituição concluída. Resultado salvo em: " << outputFilename << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (argc != 4) {
		std::cout << YELLOW <<
			"Usage: ./sedIsForLosers <filename> <s1> <s2>.\n" << RESET;
		return 1;
	}
	replaceString(filename, s1, s2);
	return (0);
}
