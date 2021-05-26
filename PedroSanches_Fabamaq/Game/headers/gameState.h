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
	class GameState : public State
	{
		public:
			GameState(GameDataRef data);

			void Init();
			void HandleInput();
			void Update(float dt);
			void Draw(float dt);

		private:
			void InitGridPieces();
			void CheckAndPlacePieces();
			void CheckHasPlayerWon(int turn);
			void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

			int _gridArray[8][8];
			int credits;
			int plays;
			int turn;
			int gameState;
		
			GameDataRef _data;

			sf::Clock _clock;

			sf::Sprite _background;
			sf::Sprite _pauseButton;
			sf::Sprite _startButton;
			sf::Sprite _creditsIN;
			sf::Sprite _creditsOUT;
			sf::Sprite _gridSprite;
			sf::Sprite _gridPieces[8][8];

			sf::Font myFont;

			sf::Text labelCredits;
			sf::Text labelPlays;
	};
}