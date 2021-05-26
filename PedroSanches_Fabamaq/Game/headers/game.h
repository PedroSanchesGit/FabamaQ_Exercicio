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

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "stateMachine.h"
#include "assetManager.h"
#include "inputManager.h"

namespace desafio
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;

	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game 
	{
		public:
			Game(int width, int height, std::string title);

		private:
			const float deltaTime = 1.0f / 60.0f;
			sf::Clock _clock;

			GameDataRef _data = std::make_shared<GameData>();

			void Start();
	};
}