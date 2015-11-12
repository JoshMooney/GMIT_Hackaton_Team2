#pragma once
#ifndef TOWER_H
#define TOWER_H

#include <SDL.h>
#include "Box2D\Box2D\Box2D.h"


class Tower
{
public:
	Tower();
	Tower(b2World *world, SDL_Renderer *ren, int x, int y);
	~Tower();
	void Update();

	//properties
	SDL_Surface* getSprite() { return sprite; }
	SDL_Rect getRect() { return spriteRect; }
	SDL_Rect getSourceRect() { return sourceRect; }
	SDL_Texture* getTexture() { return texture; }
	int getHealth() { return m_health;}
	
protected:
	SDL_Surface *sprite;
	b2FixtureDef fixdef;
	b2BodyDef bodyDef;
	b2Body* body;
	int m_health;
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect spriteRect;
};

#endif