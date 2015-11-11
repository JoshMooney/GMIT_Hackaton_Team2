#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "stdafx.h"
#include <Box2D/Box2D.h>
#include <SDL.h>
#include "Renderer.h"

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

		//Define the graphical geometry of the platfrom
		geometry = { platformBody->GetPosition().x - (width * 0.5f),
			platformBody->GetPosition().y - (height * 0.5f),
			width,
			height };
	}
	~Platform(){

	}
	void render(Renderer& r){
		r.RenderRect(&geometry, 0, 204, 0);
	}
};
#endif