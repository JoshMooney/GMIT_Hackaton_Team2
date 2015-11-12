#include "stdafx.h"
#include "Tower.h"




SDL_Texture* Tower::loadTexture(std::string path, SDL_Renderer* gRenderer) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}


		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

Tower::Tower()
{

}
Tower::Tower(b2World *world, SDL_Renderer *ren,int x, int y, std::string path)
{
	//load sprite
	//sprite = SDL_LoadBMP(path.c_str());
	//sprite = SDL_LoadBMP(path.c_str());
	//sprite = SDL_LoadBMP("Assets/tower2.bmp");
	//texture = SDL_CreateTextureFromSurface(ren,		sprite);
	texture = loadTexture(path, ren);
	//set sprites position
	spriteRect.x = x;
	spriteRect.y = y;
	spriteRect.w = 150;
	spriteRect.h = 500;
	sourceRect.w = 170;
	sourceRect.h = 500;
	fixdef = b2FixtureDef();
	fixdef.density = 1.0f;
	fixdef.friction = 0.5f;
	fixdef.restitution = 0.2f;
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(63.0f, 1.0f);
	fixdef.shape = &dynamicBox;
	m_health;
	bodyDef = b2BodyDef();
	bodyDef.type = b2_staticBody;

	bodyDef.userData = "tower";

	bodyDef.position.x = x;
	bodyDef.position.y = y - spriteRect.h;

	body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixdef);
}

Tower::~Tower() {}

void Tower::Update()
{
	spriteRect.x = body->GetPosition().x;
	spriteRect.y = body->GetPosition().y + spriteRect.h;
}