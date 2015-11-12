#pragma once
#ifndef TURRET_H
#define TURRET_H

#include <SDL.h>
#include "Box2D\Box2D\Box2D.h"


class Turret
{
public:
	Turret();
	Turret(b2World *world, SDL_Renderer *ren, int x, int y);
	~Turret();
	void Update();

	//properties
	SDL_Surface* getSprite() { return sprite; }
	SDL_Rect getRect() { return spriteRect; }
	SDL_Rect getSourceRect() { return sourceRect; }
	SDL_Texture* getTexture() { return texture; }

protected:
	SDL_Surface *sprite;

	b2FixtureDef fixdef;
	b2BodyDef bodyDef;
	b2Body* body;

	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect spriteRect;

};

#endif#pragma once
