#ifndef BASE_UNIT
#define BASE_UNIT
#include "stdafx.h"
#include <Box2D\Box2D.h>
#include <SDL.h>
#include "SDL\include\SDL_image.h"
#include "Renderer.h"
#include "CollisionResponder.h"


class Base_Unit : public CollisionResponder {
private:
	const float box2D_timestep = 1.0f / 60.0f;
public:
	//Not ment to go here but for quick development purposes sure why not.
	bool m_active;
	int m_attack;
	int m_health;
	float m_speed;
	
	bool m_direction; // 1 is looking right, 0 is looking left
	bool m_is_moving;
	bool m_is_fighting;
	b2Body* m_box_body;
	SDL_Rect m_geometry;

	int m_width = 40;
	int m_height = 40;

	//The final texture
	SDL_Texture* m_texture;
	//Load image at specified path
	SDL_Surface* loadedSurface;
	SDL_Rect* currentClip;
	SDL_Rect* sizeRec;
	Base_Unit(){}
	~Base_Unit(){}

	virtual void update() = 0;
	virtual void render(Renderer& r) = 0;
	//virtual void onEndContact(CollisionResponder* other) = 0;
	
	void attack();
	void damage(int attack) {
		m_health -= attack;
		if (m_health <= 0) {
			die();
		}
	}
	void die(){
		m_active = false;
	}
	void setTexture(SDL_Renderer* gRenderer){
		//std::string path = "Assets/heavy.png";

		//m_texture = loadTexture(path, gRenderer);
	}
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer)	{
		loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL){
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else{
			//Create texture from surface pixels
			m_texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

			SDL_Rect tempRect;
			sizeRec = new SDL_Rect{0, 0, loadedSurface->w, loadedSurface->h };
			
			if (m_texture == NULL)	{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);

		}//must return something
		return m_texture;
	}
	void move(){
		b2Vec2 pos = b2Vec2(m_box_body->GetPosition().x, m_box_body->GetPosition().y);
		if (m_direction){
			m_box_body->SetLinearVelocity(b2Vec2(m_box_body->GetLinearVelocity().x + (m_speed * box2D_timestep), m_box_body->GetLinearVelocity().y));
		}
		else{
			m_box_body->SetLinearVelocity(b2Vec2(m_box_body->GetLinearVelocity().x - (m_speed * box2D_timestep), m_box_body->GetLinearVelocity().y));
		}
	}
	void correctGeometry(){ 
		m_geometry = { (int)(m_box_body->GetPosition().x - (m_width / 2)), (int)(m_box_body->GetPosition().y - (m_height / 2)), m_width, m_height }; 
	}

	void onBeginContact(CollisionResponder* other) {
		Base_Unit* enemy = static_cast<Base_Unit*>(other);

		if (enemy != NULL) {
			damage(enemy->m_attack);
		}
		if (m_direction) {
			m_box_body->ApplyForceToCenter(b2Vec2(-30, 0), false);
		}
	}

	void onEndContact(CollisionResponder* other) {
		Base_Unit* enemy = static_cast<Base_Unit*>(other);

		if (enemy != NULL) {

		}
	}
};


#endif