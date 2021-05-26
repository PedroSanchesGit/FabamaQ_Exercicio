/* ***************************************************************  */
/* ********** Desafio Fabamaq ************************************  */
/* **                                                           **  */
/* ********** Autor: Pedro Sanches *******************************  */
/* **                                                           **  */
/* ********** Data Entrega: 15 outubro 2020 **********************  */
/* ***************************************************************  */
/* **  LINKEDIN : https://www.linkedin.com/in/pedro-ma-sanches/  ** */
/* ***************************************************************  */

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>    

#include "headers/gameState.h"
#include "headers/mainMenuState.h"
#include "headers/settings.h"
#include "headers/pauseState.h"
#include "headers/gameOverState.h"


namespace desafio
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		credits = 0;
		plays = 0;
		gameState = STATE_WAITING;
		turn = PLAYER_PIECE;

		//Seed the random functionality
		std::srand(std::time(0));

		//Load of one of the fonts to be used in the displayed labels
		myFont.loadFromFile(MYFONT);
		
		//Setting of the label that displays the current credits of the player
		labelCredits.setString("No Credits");
		labelCredits.setFont(myFont);
		labelCredits.setCharacterSize(60);
		labelCredits.setFillColor(sf::Color::Black);
		labelCredits.setPosition(this->_data->window.getSize().x / 2 - labelCredits.getLocalBounds().width / 2, this->_data->window.getSize().y - 150);

		//Setting of the label that displays the number of plays already done
		labelPlays.setString("Plays: " + std::to_string(plays));
		labelPlays.setFont(myFont);
		labelPlays.setCharacterSize(60);
		labelPlays.setFillColor(sf::Color::Black);
		labelPlays.setPosition(this->_data->window.getSize().x / 2 - labelPlays.getLocalBounds().width / 2, labelPlays.getPosition().y);

		//Load the textures of the elements that will be present in the level
		this->_data->assets.LoadTexture("Start Button", START_BUTTON);
		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Credits IN", CREDITS_IN);
		this->_data->assets.LoadTexture("Credits OUT", CREDITS_OUT);
		this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		this->_data->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("Triangulo Piece", TRIANGULO_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("Square Piece", SQUARE_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("Triangulo Winning Piece", TRIANGULO_WINNING_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("Square Winning Piece", SQUARE_WINNING_PIECE_FILEPATH);

		//Set the textures to the corresponding visual element
		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_startButton.setTexture(this->_data->assets.GetTexture("Start Button"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		_creditsIN.setTexture(this->_data->assets.GetTexture("Credits IN"));
		_creditsOUT.setTexture(this->_data->assets.GetTexture("Credits OUT"));
		_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));

		//Set the position of the buttons
		_pauseButton.setPosition(this->_data->window.getSize().x / 1 - _pauseButton.getLocalBounds().width / 1, _pauseButton.getPosition().y);
		_startButton.setPosition(this->_data->window.getSize().x / 8 - _startButton.getLocalBounds().width / 2, _startButton.getPosition().y);
		_creditsIN.setPosition(this->_data->window.getSize().x / 5 - _creditsIN.getLocalBounds().width / 2, this->_data->window.getSize().y - 150);
		_creditsOUT.setPosition(this->_data->window.getSize().x / 1.3 - _creditsOUT.getLocalBounds().width / 2, this->_data->window.getSize().y - 150);

		//Set the position of the 8x8 grid
		_gridSprite.setPosition((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));

		//Function that sets the position of each piece in each tile according to the size of the tile
		InitGridPieces();

		//Fill all the 64 spaces with the Empty Space definition (The game only starts after hit the button Start, if the player has credits)
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				_gridArray[x][y] = EMPTY_PIECE;
			}
		}
	}

	//Function that handles the input triggers of the player
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			//Close the window ending the game
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			//If the player clicks on one of the specific sprites, the next events will trigger
			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Game State
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false);

				gameState = STATE_PAUSED;
			}
			else if (this->_data->input.IsSpriteClicked(this->_startButton, sf::Mouse::Left, this->_data->window))
			{
				//Make sure the player has credits to be able to play
				if (GameState::credits > 0)
				{
					gameState = STATE_PLAYING;

					plays++;
					labelPlays.setString("Plays: " + std::to_string(plays));
					
					//Clean board from previous game
					for (int x = 0; x < 8; x++)
					{
						for (int y = 0; y < 8; y++)
						{
							_gridArray[x][y] = EMPTY_PIECE;
						}
					}

					//Place the 64 pieces
					this->CheckAndPlacePieces();

				}
				
				
			}
			else if (this->_data->input.IsSpriteClicked(this->_creditsIN, sf::Mouse::Left, this->_data->window))
			{
				//The button to add credits was triggered
				GameState::credits++;
				labelCredits.setString(std::to_string(GameState::credits));
			}
			else if (this->_data->input.IsSpriteClicked(this->_creditsOUT, sf::Mouse::Left, this->_data->window))
			{
				//The button to withdraw the credits was triggered
				GameState::credits = 0;
				labelCredits.setString("No Credits");
			}
		}
	}

	void GameState::Update(float deltaTime)
	{
		//If the player looses a round (doesn't get any 3 row combination) and does not have any more credits... it's the end of the game
		if (STATE_LOSE == gameState && GameState::credits <= 0)
		{
			if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER)
			{
				// Switch To Main Menu
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
		//If the player looses or wins, he can continue to play, so the game is waiting for new input
		else 
		{
			gameState = STATE_WAITING;
		}
	}

	//Every element is drawn on the screen
	void GameState::Draw(float deltaTime)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.draw(this->_startButton);
		
		this->_data->window.draw(this->_pauseButton);
		
		this->_data->window.draw(this->_creditsIN);

		this->_data->window.draw(this->_creditsOUT);

		this->_data->window.draw(this->_gridSprite);

		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				this->_data->window.draw(this->_gridPieces[x][y]);
			}
		}

		this->_data->window.draw(labelCredits);

		this->_data->window.draw(labelPlays);

		this->_data->window.display();
	}

	//Function that is executed only at the begginning of the game to initialize the board
	void GameState::InitGridPieces()
	{
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X Piece").getSize();

		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X Piece"));
				_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7, _gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
				_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}

	//Function that makes the move everytime the player hits "Start". This function fills the board with 4 different types of pieces and checks if there's 3 in a row (horizontal, vertical or diagonal)
	void GameState::CheckAndPlacePieces()
	{

		std::vector<int> getRandomPiece = { X_PIECE, O_PIECE, TRIANGULO_PIECE, SQUARE_PIECE };

		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				if (_gridArray[column][row] == EMPTY_PIECE)
				{
					//Get a random index. This is a number between 0 and 3 that represents the position of the vector that has 1 of the 4 pieces of the game
					int index = std::rand() % 4;

					_gridArray[column][row] = getRandomPiece[index];

					if (getRandomPiece[index] == X_PIECE)
					{
						_gridPieces[column][row].setTexture(this->_data->assets.GetTexture("X Piece"));

					}
					else if (getRandomPiece[index] == O_PIECE)
					{
						_gridPieces[column][row].setTexture(this->_data->assets.GetTexture("O Piece"));

					}
					else if (getRandomPiece[index] == TRIANGULO_PIECE)
					{
						_gridPieces[column][row].setTexture(this->_data->assets.GetTexture("Triangulo Piece"));

					}
					else if (getRandomPiece[index] == SQUARE_PIECE)
					{
						_gridPieces[column][row].setTexture(this->_data->assets.GetTexture("Square Piece"));

					}

					_gridPieces[column][row].setColor(sf::Color(255, 255, 255, 255));
				}
			}
		}

		//This is the function that identifies if there's some matches in the round. If there is, the player wins one credit. If not, he looses one.
		this->CheckHasPlayerWon(turn);

		
	}

	//This is the function that identifies if there's some matches in the round. If there is, the player wins one credit. If not, he looses one.
	void GameState::CheckHasPlayerWon(int player)
	{
		
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				//Verify all columns
				Check3PiecesForMatch(x, y, x, y + 1, x, y + 2, player);
			}
		}

		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 6; x++)
			{
				//Verify all rows
				Check3PiecesForMatch(x, y, x + 1, y, x + 2, y, player);
			}
		}

		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{

				//Verificar diagonals
				if (x - 1 >= 0 && y - 1 >= 0 && x - 2 >= 0 && y - 2 >= 0)
				{
					Check3PiecesForMatch(x, y, x - 1, y - 1, x - 2, y - 2, player);
				}
				else if (x + 1 >= 0 && y - 1 >= 0 && x + 2 >= 0 && y - 2 >= 0)
				{
					Check3PiecesForMatch(x, y, x + 1, y - 1, x + 2, y - 2, player);
				}
			}
		}
		
	
		if (gameState != STATE_WON)
		{
			//If didn't won, then it looses a credit
			GameState::credits--;
			labelCredits.setString(std::to_string(GameState::credits));
			
			if (GameState::credits <= 0)
			{
				labelCredits.setString("No Credits");
				gameState = STATE_LOSE;

				// show game over
				this->_clock.restart();
			}
			
		}
		else 
		{
			//If the player was victorious, then it gain a new credit
			GameState::credits++;
			labelCredits.setString(std::to_string(GameState::credits));
		}

	}

	//Function that checks if 3 pieces match
	void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		if (pieceToCheck == _gridArray[x1][y1] && pieceToCheck == _gridArray[x2][y2] && pieceToCheck == _gridArray[x3][y3])
		{
			std::string winningPieceStr;

			if (PLAYER_PIECE == pieceToCheck)
			{
				if (PLAYER_PIECE == X_PIECE)
				{
					winningPieceStr = "X Winning Piece";
				}
				else if (PLAYER_PIECE == O_PIECE)
				{
					winningPieceStr = "O Winning Piece";
				}
				else if (PLAYER_PIECE == TRIANGULO_PIECE)
				{
					winningPieceStr = "Triangulo Winning Piece";
				}
				else if (PLAYER_PIECE == SQUARE_PIECE)
				{
					winningPieceStr = "Square Winning Piece";
				}
				
				
			}

			_gridPieces[x1][y1].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x2][y2].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x3][y3].setTexture(this->_data->assets.GetTexture(winningPieceStr));


			if (PLAYER_PIECE == pieceToCheck)
			{
				gameState = STATE_WON;
			}
			
		}
	}
}