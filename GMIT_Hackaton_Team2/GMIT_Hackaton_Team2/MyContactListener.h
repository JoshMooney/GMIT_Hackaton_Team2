#ifndef _MYCONTACTLISTENER_H
#define _MYCONTACTLISTENER_H
#include <Box2D\Dynamics\Contacts\b2Contact.h>
#include "Base_Unit.hpp"
#include "Tower.h"

class MyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact) override {

		Platform* platform = static_cast<Platform*>(contact->GetFixtureA()->GetBody()->GetUserData());
		Platform* platformB = static_cast<Platform*>(contact->GetFixtureB()->GetBody()->GetUserData());
		if (platform) {
			return;
		}
		if (platformB) {
			return;
		}
		CollisionResponder* bodyUserDataA = static_cast<CollisionResponder*>(contact->GetFixtureA()->GetBody()->GetUserData());
		CollisionResponder* bodyUserDataB = static_cast<CollisionResponder*>(contact->GetFixtureB()->GetBody()->GetUserData());
		
		if (bodyUserDataA && bodyUserDataB){
			bodyUserDataA->onBeginContact(bodyUserDataB);
		}
		if (bodyUserDataB && bodyUserDataA){
			bodyUserDataB->onBeginContact(bodyUserDataA);
		}
	}

	void EndContact(b2Contact* contact) override {

		CollisionResponder* bodyUserDataA = static_cast<CollisionResponder*>(contact->GetFixtureA()->GetBody()->GetUserData());
		CollisionResponder* bodyUserDataB = static_cast<CollisionResponder*>(contact->GetFixtureB()->GetBody()->GetUserData());
		if (bodyUserDataA && bodyUserDataB){
			bodyUserDataA->onEndContact(bodyUserDataB);
		}
		if (bodyUserDataB && bodyUserDataA){
			bodyUserDataB->onEndContact(bodyUserDataA);
		}
	}
};
#endif