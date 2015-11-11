#include "stdafx.h"
#include "InputManager.h"
#include <iostream>
using namespace std;
InputManager::InputManager()
{
	clearInputs();
}

void InputManager::clearInputs()
{
	playerOutput[LEFT] = false;
	playerOutput[RIGHT] = false;
	playerOutput[UP] = false;
	playerOutput[ACTION] = false;

	gameOutput[RESET] = false;
	gameOutput[QUIT] = false;
	gameOutput[FFW] = false;
	gameOutput[CLICK] = false;
}

//I'd like this to be const since you can currently change the bools
tuple<bool, bool, bool, bool> InputManager::getPlayerKeys() const
{
	return make_tuple(playerOutput[LEFT], playerOutput[RIGHT], playerOutput[UP], playerOutput[ACTION]);
}

tuple<bool, bool, bool, bool> InputManager::getGameKeys() const
{
	return make_tuple(gameOutput[RESET], gameOutput[QUIT], gameOutput[FFW], gameOutput[CLICK]);
}

void InputManager::update()
{

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT) //user presses close button on window
		{
			gameOutput[QUIT] = true;
		}

		//User presses a key
		else
		{
			if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
					//Esc : Exit	
				case SDLK_ESCAPE://user presses esc key
					gameOutput[QUIT] = true;
					continue;

					//F5 : Reset
				case SDLK_F5:
					gameOutput[RESET] = true;
					continue;
					//R : Reset
				case SDLK_r:
					gameOutput[RESET] = true;
					continue;
				}//end keydown switch
			}//end keydown if

			if (e.type == SDL_KEYUP)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
					//Esc : Exit	
				case SDLK_ESCAPE://user presses esc key
					gameOutput[QUIT] = false;
					continue;

					//F5 : Reset
				case SDLK_F5:
					gameOutput[RESET] = false;
					continue;
					//R : Reset
				case SDLK_r:
					gameOutput[RESET] = false;
					continue;

					//Backspace : Fastforward time
				case SDLK_BACKSPACE:
					gameOutput[FFW] = false;
					continue;

					//A : Left
				case SDLK_a:
					playerOutput[LEFT] = false;
					continue;
					//LEFT : Left
				case SDLK_LEFT:
					playerOutput[LEFT] = false;
					continue;

					//D : Right
				case SDLK_d:
					playerOutput[RIGHT] = false;
					continue;
					//RIGHT : Right
				case SDLK_RIGHT:
					playerOutput[RIGHT] = false;
					continue;

					//W : Jump
				case SDLK_w:
					playerOutput[UP] = false;
					continue;
					//UP : Jump
				case SDLK_UP:
					playerOutput[UP] = false;
					continue;
					//SPACE : Jump;
				case SDLK_SPACE:
					playerOutput[UP] = false;
					continue;

					//Left Shift : Action
				case SDLK_LSHIFT:
					playerOutput[ACTION] = false;
					continue;
					//E  : Action
				case SDLK_e:
					playerOutput[ACTION] = false;
					continue;

				}//end keyup switch
			}//end keyup if
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				//If the left mouse button was pressed 
				if (e.button.button == SDL_BUTTON_LEFT) {
					gameOutput[CLICK] = true;
				}
			}
			if (e.type == SDL_MOUSEBUTTONUP) {
				//If the left mouse button was pressed 
				if (e.button.button == SDL_BUTTON_LEFT) {
					gameOutput[CLICK] = false;
					cout << e.button.x, e.button.y;
				}
			}

		}//end key else 
	}//end pollevent
}