#ifndef HEAVY_UNIT
#define HEAVY_UNIT
#include "stdafx.h"
#include "Renderer.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Heavy_Unit : public Base_Unit{
private:

public:
	Heavy_Unit();
	Heavy_Unit(b2Vec2 pos, bool dir, b2World* wrd, Renderer &r){
		loadTexture("Assets/player.png", r.getRender());
		m_attack = 30;
		m_health = 20;
		m_speed = 10;

		m_direction = dir;
		m_geometry = {}
	}
	~Heavy_Unit();

	void update();
	void render(Renderer& r);
	void onBeginContact(CollisionResponder* other);
	void onEndContact(CollisionResponder* other);
};

#endif