#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "Box2D\Box2D.h"
#include "Enemy.h"
#include "Platform.h"


class ContactListener : public b2ContactListener {
private:
	Level* level;
	Menu* menu;
public:

	ContactListener(Menu* mnu) : b2ContactListener() {
		menu = mnu;
	}

	void BeginContact(b2Contact* contact)
	{
		void* fixAType = contact->GetFixtureA()->GetUserData();
		void* fixBType = contact->GetFixtureB()->GetUserData();

		if (fixAType == "Enemy" && fixBType == "Enemy"
			|| fixAType == "Enemy" && fixBType == "Enemy") {
			if (fixAType == "Enemy") {
				void* body1 = contact->GetFixtureA()->GetBody();
				void* body2 = contact->GetFixtureB()->GetBody();
				


			}

		}
};
#endif