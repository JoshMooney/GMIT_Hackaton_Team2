#ifndef HEAVY_UNIT
#define HEAVY_UNIT

#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Heavy_Unit : public Base_Unit {

public:
	Heavy_Unit(){

	}
	Heavy_Unit(b2Vec2 pos, int w, int h, bool dir, b2World* wrd, Renderer &r) {
		m_texture = loadTexture("Assets/heavy.png", r.getRender());
		//Define a b2body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = b2Vec2(pos.x, pos.y);
		bodyDef.userData = this;
		m_active = true;
		//Ask the b2Worldto create our body
		m_box_body = wrd->CreateBody(&bodyDef);

		m_geometry = { (int)(m_box_body->GetPosition().x - (w / 2)), (int)(m_box_body->GetPosition().y - (h / 2)), w, h };
		
		//Define the shape of the body
		b2PolygonShape shape;
		shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		m_box_body->CreateFixture(&shape, 0.0f);
		m_box_body->GetFixtureList()->SetFriction(0.0f);
		m_box_body->GetFixtureList()->SetRestitution(0.0f);
		/*
		//Define the shape of the body
		b2PolygonShape l_shape;
		l_shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		b2FixtureDef mFixtureDef;
		mFixtureDef.userData = "Enemy";
		mFixtureDef.shape = &l_shape;
		mFixtureDef.density = 1.0f;
		mFixtureDef.friction = 0.0f;
		mFixtureDef.restitution = 0.0f;

		b2PolygonShape shape;
		shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		m_box_body->CreateFixture(&shape, 0.0f);

		m_box_body->CreateFixture(&mFixtureDef);
		//m_box_body->SetFixedRotation(true);
		*/
		m_attack = 30;
		m_health = 20;
		m_speed = .1f;
		m_is_moving = false;
		m_is_fighting = false;
		m_direction = dir;
		m_geometry = { (int)(m_box_body->GetPosition().x - (w / 2)), (int)(m_box_body->GetPosition().y - (h / 2)), w, h };
	}
	~Heavy_Unit(){

	}

	void update(){
		move();
		correctGeometry();
	}
	void render(Renderer& r){
		//SDL_RenderCopy(r.getRender(), m_texture, NULL, &m_geometry);
		r.DrawImage(sizeRec, &m_geometry, m_texture);
	}
	void onBeginContact(CollisionResponder* other){

	}
	void onEndContact(CollisionResponder* other){

	}
};

#endif