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
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float deltaTime);
		void Draw(float deltaTime);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _playButton;

		sf::Sprite _playButtonOuter;

		sf::Sprite _title;
	};
}