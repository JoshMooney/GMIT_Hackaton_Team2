#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "stdafx.h"
#include <Box2D/Box2D.h>
#include <SDL.h>
#include "Renderer.h"
#include "SDL\include\SDL_image.h"

class Platform{
private:
	b2Body* platformBody;
	SDL_Rect geometry;
public:
	Platform(b2Vec2 const &position, int width, int height, b2World *m_world){
		b2BodyDef myBodyDef;
		myBodyDef.type = b2_staticBody; //this will be a static body
		myBodyDef.position = b2Vec2((position.x + width*0.5f), (position.y + height*0.5f)); //set the starting position
		myBodyDef.angle = 0; //set the starting angle
		myBodyDef.userData = this;

		platformBody = m_world->CreateBody(&myBodyDef);
		//Define the shape 
		b2PolygonShape shape;
		shape.SetAsBox(width * 0.5f, height * 0.5f);
		platformBody->CreateFixture(&shape, 0.0f);
		geometry = SDL_Rect();
		
		//Define the graphical geometry of the platfrom
		geometry.x = platformBody->GetPosition().x - ((float32)width * 0.5f);
		geometry.y = platformBody->GetPosition().y - ((float32)height * 0.5f);
		geometry.h = (float32)height;
		geometry.w = (float32)width;

		
	}
	~Platform(){

	}
	void render(Renderer& r){
		r.RenderRect(&geometry, 0, 204, 0);
	}
};
#endif