#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <iostream>
#include <stdio.h>

#include <windows.h>

#include <random>
#include <string>
#include <cmath>

#include <fstream>

#include <SDL.h>
#include "Renderer.h"

static class Button
{
private:
	SDL_Rect rect;
	SDL_Surface surf;
	SDL_Texture* myTexture;
	SDL_Texture* loadTexture(std::string path, SDL_Renderer*);
public:

	Button();
	void Init(SDL_Rect pos, SDL_Renderer*, std::string path);
	bool IsClicked(int x, int y);
	void Draw(Renderer);


};
#endif