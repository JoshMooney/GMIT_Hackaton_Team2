#include "stdafx.h"
#include <SDL.h>
#undef main 
#include "Box2D\Box2D.h"
using namespace std;
#include <iostream>
#include "Renderer.h"
#include "Platform.h"
#include "Light_Unit.hpp"
#include "Heavy_Unit.hpp"
#include "Light_Unit.hpp"
#include "InputManager.h"
#include "Unit_Manager.hpp"
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
	const b2Vec2 GRAVITY = b2Vec2(0, 9.8f);
	const float box2D_timestep = 1.0f / 60.0f;
	const int vel_iterations = 6;
	const int pos_iterations = 2;

	b2World* m_world;
	m_world = new b2World(GRAVITY);

	Unit_Manager unit_manager = Unit_Manager();
	
	SDL_Rect worldBounds = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Renderer renderer = Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
	Platform main_platform = Platform(b2Vec2(0, 600), 960, 40, m_world);
	InputManager im;
	Tower tower = Tower(m_world, renderer.getRender(), 100, 100);

	unit_manager.addUnit("Heavy", true, m_world, renderer);
	unit_manager.addUnit("Med", false, m_world, renderer);
	unit_manager.addUnit("Light", true, m_world, renderer);

	bool is_running = true;
	while (is_running){
		//Main Game loop here
		m_world->Step(box2D_timestep, vel_iterations, pos_iterations);

		unit_manager.update();
		unit_manager.cullUnits(m_world);
		im.update();
		renderer.Begin();
		//Draw in here
		main_platform.render(renderer);
		renderer.DrawImage(&tower.getSourceRect(), &tower.getRect(), tower.getTexture());
		unit_manager.render(renderer);

		//if () {}

		renderer.End();
	}

	return EXIT_SUCCESS;
}

