#ifndef LIGHT_UNIT
#define LIGHT_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Light_Unit : public Base_Unit{
private:
	int IdleTimer;
	int returnIdle;
public:
	Light_Unit();
	Light_Unit(b2Vec2 pos, int w, int h, bool dir, b2World* wrd, Renderer &r) {
		m_texture = loadTexture("Assets/light.png", r.getRender());
		m_active = true;
		//Define a b2body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		m_active = true;
		bodyDef.position = b2Vec2(pos.x, pos.y);
		bodyDef.userData = this;
		//Ask the b2Worldto create our body
		m_box_body = wrd->CreateBody(&bodyDef);

		m_geometry = { (int)(m_box_body->GetPosition().x - (w / 2)), (int)(m_box_body->GetPosition().y - (h / 2)), w, h };

		//Define the shape of the body
		b2PolygonShape shape;
		shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		m_box_body->CreateFixture(&shape, 0.0f);
		m_box_body->GetFixtureList()->SetFriction(0.0f);
		m_box_body->GetFixtureList()->SetRestitution(0.0f);

		m_attack = 10;
		m_health = 10;
		m_speed = .3f;

		m_is_moving = false;
		m_is_fighting = false;
		m_direction = dir;
		initAnimation();

		frame = 0;
		frameDelay = 50;
		IdleTimer = 50;
		returnIdle = 0;
		frameCountdown = 0;
	}
	~Light_Unit();

	void update(){
		//Go to next frame
		if (++frameCountdown > frameDelay) {
			frame++;
			frameCountdown = 0;
		}
		//Cycle animation
		//if (frame / 3 >= WALKING_ANIMATION_FRAMES){
		if (frame >= WALKING_ANIMATION_FRAMES) {
			frame = 0;
		}
		move();
		correctGeometry();
	}
	void render(Renderer& r){
		//SDL_RenderCopy(r.getRender(), m_texture, NULL, &m_geometry);
		//r.DrawImage(sizeRec, &m_geometry, m_texture);
		if (m_direction)
			currentClip = &right_Clips[frame];
		else
			currentClip = &left_Clips[frame];
		SDL_RenderCopy(r.getRender(), m_texture, currentClip, &m_geometry);
	}
	void onBeginContact(CollisionResponder* other){

	}
	void onEndContact(CollisionResponder* other){

	}
};

#endif