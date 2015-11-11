#ifndef LIGHT_UNIT
#define LIGHT_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Light_Unit : public Base_Unit{
private:

public:
	Light_Unit();
	Light_Unit(bool dir, b2World* wrd);
	~Light_Unit();

	void update();
	void render(Renderer& r);
	void onBeginContact(CollisionResponder* other);
	void onEndContact(CollisionResponder* other);
};

#endif