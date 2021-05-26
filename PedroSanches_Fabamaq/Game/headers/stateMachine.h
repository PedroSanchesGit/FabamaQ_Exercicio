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
#include <stack>

#include "state.h"

namespace desafio 
{

	typedef std::unique_ptr<State> StateRef;

	class StateMachine 
	{
		public:
			StateMachine(){}
			~StateMachine(){}

			void AddState(StateRef newState, bool isReplacing = true);
			void RemoveState();
			void ProcessStateChanges();

			StateRef &GetActiveState();

		private:
			std::stack<StateRef> _states;
			StateRef _newState;

			bool _isRemoving;
			bool _isAdding;
			bool _isReplacing;
	};

}