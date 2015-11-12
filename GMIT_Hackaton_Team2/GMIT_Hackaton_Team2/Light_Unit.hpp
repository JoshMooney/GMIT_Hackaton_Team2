#ifndef LIGHT_UNIT
#define LIGHT_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Light_Unit : public Base_Unit{
private:

public:
	Light_Unit();
	Light_Unit(b2Vec2 pos, int w, int h, bool dir, b2World* wrd, Renderer &r) {
		loadTexture("Assets/light.png", r.getRender());
		//Define a b2body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = b2Vec2(m_geometry.x, m_geometry.y);
		bodyDef.userData = this;
		//Ask the b2Worldto create our body
		m_box_body = wrd->CreateBody(&bodyDef);

		//Define the shape of the body
		b2PolygonShape shape;
		shape.SetAsBox(m_geometry.w * 0.5f, m_geometry.h * 0.5f);
		m_box_body->CreateFixture(&shape, 0.0f);
		m_box_body->GetFixtureList()->SetFriction(0.0f);
		m_box_body->GetFixtureList()->SetRestitution(0.0f);

		m_attack = 30;
		m_health = 20;
		m_speed = 10;
		m_is_moving = false;
		m_is_fighting = false;
		m_direction = dir;
		m_geometry = { (int)(m_box_body->GetPosition().x - (w / 2)), (int)(m_box_body->GetPosition().y - (h / 2)), w, h };
	}
	~Light_Unit();

	void update();
	void render(Renderer& r);
	void onBeginContact(CollisionResponder* other);
	void onEndContact(CollisionResponder* other);
};

#endif