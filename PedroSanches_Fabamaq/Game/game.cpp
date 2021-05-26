/* ***************************************************************  */
/* ********** Desafio Fabamaq ************************************  */
/* **                                                           **  */
/* ********** Autor: Pedro Sanches *******************************  */
/* **                                                           **  */
/* ********** Data Entrega: 15 outubro 2020 **********************  */
/* ***************************************************************  */
/* **  LINKEDIN : https://www.linkedin.com/in/pedro-ma-sanches/  ** */
/* ***************************************************************  */

#include "headers/game.h"
#include "headers/splashState.h"

namespace desafio
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Start();
	}

	void Game::Start()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();

		float accumulator = .0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > .25f)
			{
				frameTime = .25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= deltaTime)
			{
				this->_data->machine.GetActiveState()->HandleInput();

				this->_data->machine.GetActiveState()->Update(deltaTime);

				accumulator -= deltaTime;
			}

			interpolation = accumulator / deltaTime;

			this->_data->machine.GetActiveState()->Draw(interpolation);

		}
	}
}