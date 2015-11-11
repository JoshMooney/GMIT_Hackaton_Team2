#ifndef HEAVY_UNIT
#define HEAVY_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Heavy_Unit : public Base_Unit{
private:

public:
	Heavy_Unit();
	Heavy_Unit(bool dir, b2World* wrd){
		
	}
	~Heavy_Unit();

	void update();
	void render(Renderer& r);
	void onBeginContact(CollisionResponder* other);
	void onEndContact(CollisionResponder* other);
};

#endif