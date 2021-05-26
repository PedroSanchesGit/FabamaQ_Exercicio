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

namespace desafio {

	class State
	{
		public:
			virtual void Init() = 0;
			virtual void HandleInput() = 0;
			virtual void Update(float deltaTime) = 0;
			virtual void Draw(float deltaTime) = 0;
			virtual void Pause() {}
			virtual void Resume() {}

	};
}