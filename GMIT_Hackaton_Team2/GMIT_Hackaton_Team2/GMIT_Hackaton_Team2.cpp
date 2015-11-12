#include "stdafx.h"
#include <SDL.h>
#undef main 
#include "Box2D\Box2D\Box2D.h"

using namespace std;
#include <iostream>
#include "Renderer.h"

#include "Platform.h"
#include "InputManager.h"
#include "Tower.h"


/*
Notes:
How to use ResourceManager:

ResourceManager<DataTypeHere>::instance()->("Path");
eg.
ResourceManager<sf::Texture>::instance()->("Assets/Stuff/file.png")
*/



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

	b2World* m_world;
	m_world = new b2World(GRAVITY);

	SDL_Rect worldBounds = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer renderer = Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
	Platform main_platform = Platform(b2Vec2(0, 600), 960, 40, m_world);
	Tower tower = Tower(m_world, renderer.getRender(), 100, 100);
	Tower towerTwo = Tower(m_world, renderer.getRender(), 760, 100);
	InputManager im;



	bool is_running = true;
	while (is_running){
		SDL_Event e;
		//Main Game loop here

		m_world->Step(box2D_timestep, vel_iterations, pos_iterations);

		im.update();


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
		renderer.DrawImage(&towerTwo.getSourceRect(), &towerTwo.getRect(), towerTwo.getTexture());
		main_platform.render(renderer);
		renderer.End();
	}

	return EXIT_SUCCESS;
}

