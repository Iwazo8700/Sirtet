#pragma once

#include <fstream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <iostream>

/*! \brief
 *
 *
 * Classe Formato
 * Model responsavel por carregar e armazenar os dados
 * dos possiveis formatos, guardando em matrizes de
 * boleanos
 * */

class Formato {
	private:
		std::vector<std::vector<std::vector<bool>>> formatos; /*!< Vetor com as matrizes de formatos*/
		std::vector<char> names;
	public:
		/*! \brief Construtor do Formato
		 * Deve receber um caminho para o arquivo onde estão armazenados os formatos usados no jogo
		 *
		 * \param char const *dir
		 * */	
		Formato(char const *dir);
		std::vector<std::vector<bool>> get_formato(char nome);
		char get_nome(std::vector<std::vector<bool>> vect);
		std::vector<std::vector<bool>> get_I();
		std::vector<std::vector<bool>> get_O();
		std::vector<std::vector<bool>> get_J();
		std::vector<std::vector<bool>> get_L();
		std::vector<std::vector<bool>> get_S();
		std::vector<std::vector<bool>> get_Z();
		std::vector<std::vector<bool>> get_T();
		std::vector<std::vector<bool>> get_random();
};
