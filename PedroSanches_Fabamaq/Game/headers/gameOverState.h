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
	class GameOverState : public State
	{
		public:
			GameOverState(GameDataRef data);

			void Init();

			void HandleInput();
			void Update(float dt);
			void Draw(float dt);

		private:
			GameDataRef _data;

			sf::Sprite _retryButton;
			sf::Sprite _homeButton;

	};
}