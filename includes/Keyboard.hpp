#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <vector>
#include <iostream>
#include "Bloco.hpp"
#include "Collision.hpp"


/*! \brief
 *
 * Classe Keyboard
 * Controller responsável por ler as infromações do teclado
 * e atualizar a peça
 *
 *
 * */

class Keyboard{
	private:
		SDL_Event evento; // eventos discretos
 		const Uint8* state; // estado do teclado
		std::shared_ptr<Bloco> bloco;
		bool Rot_atraso = false;
		bool Desloc_atraso = false;
		bool Space_atraso = false;
	public:
		Keyboard(std::shared_ptr<Bloco> bloco);
		void set_bloco(std::shared_ptr<Bloco> bloco);
		std::vector<std::vector<bool>> Rotation();
		bool Quit();
		int Desloc();
		std::vector<std::vector<bool>> RotHoraria();
		std::vector<std::vector<bool>> RotAnti();
		int Space(std::shared_ptr<Collision> collision);
		int Down(std::shared_ptr<Collision> collision);

};
