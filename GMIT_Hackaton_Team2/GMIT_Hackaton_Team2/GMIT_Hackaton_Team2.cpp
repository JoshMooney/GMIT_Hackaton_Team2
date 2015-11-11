#include "stdafx.h"

#include <SDL.h>
#undef main 
#include "Box2D\Box2D\Box2D.h"

using namespace std;
#include <iostream>
#include "Renderer.h"
#include "Tower.h"

int main(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		system("timeout 10");
		return EXIT_FAILURE;
	}
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 640;
	const b2Vec2 GRAVITY = b2Vec2(0, 9.81f);
	const float box2D_timestep = 1.0f / 60.0f;
	const int vel_iterations = 6;
	const int pos_iterations = 2;
	SDL_Rect worldBounds = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer renderer = Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
	b2World world(GRAVITY);
	Tower tower = Tower(&world, renderer.getRender(), 100, 100);
	bool is_running = true;
	while (is_running){
		SDL_Event e;
		//Main Game loop here
		while (SDL_PollEvent(&e) != 0)
		{

			//User requests quit
			if (e.type == SDL_QUIT) //user presses close button on window
			{
				is_running = false;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					is_running = false;
					break;
				default:
					break;
				}


			}
		}
		renderer.Begin();
		renderer.DrawImage(&tower.getSourceRect(), &tower.getRect(), tower.getTexture());
		renderer.End();
	}

	return EXIT_SUCCESS;
}

