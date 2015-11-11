#ifndef MED_UNIT
#define MED_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include "Base_Unit.hpp"

class Med_Unit : public Base_Unit {
private:

public:
	Med_Unit();
	Med_Unit(bool dir, b2World* wrd);
	~Med_Unit();

	void update();
	void render(Renderer& r);
	void onBeginContact(CollisionResponder* other);
	void onEndContact(CollisionResponder* other);
};

#endif