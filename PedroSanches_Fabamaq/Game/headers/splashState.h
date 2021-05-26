/* ***************************************************************  */
/* ********** Desafio Fabamaq ************************************  */
/* **                                                           **  */
/* ********** Autor: Pedro Sanches *******************************  */
/* **                                                           **  */
/* ********** Data Entrega: 15 outubro 2020 **********************  */
/* ***************************************************************  */
/* **  LINKEDIN : https://www.linkedin.com/in/pedro-ma-sanches/  ** */
/* ***************************************************************  */

#pragma once

#include <SFML/Graphics.hpp>

#include "state.h"
#include "game.h"

namespace desafio
{
	class SplashState : public State
	{
		public:
			SplashState(GameDataRef data);

			void Init();
			void HandleInput();
			void Update(float deltaTime);
			void Draw(float deltaTime);

		private:
			GameDataRef _data;

			sf::Clock _clock;

			sf::Texture _backgroundTexture;
			sf::Sprite _background;
	};
}