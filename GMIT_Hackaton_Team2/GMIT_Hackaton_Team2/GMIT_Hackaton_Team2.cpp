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
#include "Button.h"

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
	Button b1;
	Button b2;
	Button b3;

	Button b4;
	Button b5;
	Button b6;

	SDL_Rect temp = { 10, 10, 150, 50 };
	b1.Init(temp, renderer.getRender(), "enemy2button.png");
	temp = { 10, 70, 150, 50 };
	b2.Init(temp, renderer.getRender(), "enemy1button.png");
	temp = { 10, 130, 150, 50 };
	b3.Init(temp, renderer.getRender(), "enemy3button.png");

	temp = { 800, 10, 150, 50 };
	b4.Init(temp, renderer.getRender(), "redenemy2.png");
	temp = { 800, 70, 150, 50 };
	b5.Init(temp, renderer.getRender(), "redenemy1.png");
	temp = { 800, 130, 150, 50 };
	b6.Init(temp, renderer.getRender(), "redenemy3.png");

	//unit_manager.addUnit("Heavy", true, m_world, renderer);
	//unit_manager.addUnit("Heavy", false, m_world, renderer);
	

	bool is_running = true;
	while (is_running){
		//Main Game loop here
		m_world->Step(box2D_timestep, vel_iterations, pos_iterations);

		unit_manager.update();
		unit_manager.cullUnits(m_world);
		im.update();

		if (b1.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Heavy", true, m_world, renderer);
		}
		if (b2.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Med", true, m_world, renderer);
		}
		if (b3.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Light", true, m_world, renderer);
		}

		//----------------
		if (b4.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Heavy", false, m_world, renderer);
		}
		if (b5.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Med", false, m_world, renderer);
		}
		if (b6.IsClicked(im.getX(), im.getY()))
		{
			cout << "You clicked da button" << endl;
			unit_manager.addUnit("Light", false, m_world, renderer);
		}

		renderer.Begin();
		//Draw in here
		main_platform.render(renderer);
		renderer.DrawImage(&tower.getSourceRect(), &tower.getRect(), tower.getTexture());
		unit_manager.render(renderer);

		//if () {}
		b1.Draw(renderer);
		b2.Draw(renderer);
		b3.Draw(renderer);

		b4.Draw(renderer);
		b5.Draw(renderer);
		b6.Draw(renderer);
		renderer.End();
	}

	return EXIT_SUCCESS;
}

