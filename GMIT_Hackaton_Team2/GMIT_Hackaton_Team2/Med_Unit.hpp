#ifndef MED_UNIT
#define MED_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Med_Unit : public Base_Unit {
private:

public:
	Med_Unit();
	Med_Unit(b2Vec2 pos, int w, int h, bool dir, b2World* wrd, Renderer &r) {
		m_texture = loadTexture("Assets/med.png", r.getRender());
		//Define a b2body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = b2Vec2(pos.x, pos.y);
		bodyDef.userData = this;
		//Ask the b2Worldto create our body
		m_box_body = wrd->CreateBody(&bodyDef);

		//Define the shape of the body
		b2PolygonShape shape;
		shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		m_box_body->CreateFixture(&shape, 0.0f);
		m_box_body->GetFixtureList()->SetFriction(0.0f);
		m_box_body->GetFixtureList()->SetRestitution(0.0f);

		m_attack = 20;
		m_health = 20;
		m_speed = .2f;
		m_is_moving = false;
		m_is_fighting = false;
		m_direction = dir;
		m_geometry = { (int)(m_box_body->GetPosition().x - (w / 2)), (int)(m_box_body->GetPosition().y - (h / 2)), w, h };
	}
	~Med_Unit();

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