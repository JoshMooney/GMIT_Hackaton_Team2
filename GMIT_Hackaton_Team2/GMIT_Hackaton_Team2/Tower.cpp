#include "stdafx.h"
#include "Tower.h"

Tower::Tower()
{

}
Tower::Tower(b2World *world, SDL_Renderer *ren,int x, int y)
{
	//load sprite
	sprite = SDL_LoadBMP("Assets/Images/tower.bmp");
	texture = SDL_CreateTextureFromSurface(ren,
		sprite);
	//set sprites position
	spriteRect.x = x;
	spriteRect.y = y;
	spriteRect.w = sprite->w;
	spriteRect.h = sprite->h;
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = sprite->w;
	sourceRect.h = sprite->h;
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