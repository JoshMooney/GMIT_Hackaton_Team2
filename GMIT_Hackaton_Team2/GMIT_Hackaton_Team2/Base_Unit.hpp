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

public:
	//Not ment to go here but for quick development purposes sure why not.
	int m_attack;
	int m_health;
	float m_speed;
	
	bool m_direction;
	bool m_is_moving;
	bool m_is_fighting;
	b2Body* m_box_body;
	SDL_Rect m_geometry;

	//The final texture
	SDL_Texture* newTexture;
	//Load image at specified path
	SDL_Surface* loadedSurface;
	SDL_Rect* currentClip;

	Base_Unit();
	~Base_Unit();

	virtual void update() = 0;
	virtual void render(Renderer& r) = 0;
	virtual void onBeginContact(CollisionResponder* other) = 0;
	virtual void onEndContact(CollisionResponder* other) = 0;
	
	void setTexture(SDL_Renderer* gRenderer){
		std::string path = "Assets/player.png";

		myTexture = loadTexture(path, gRenderer);
	}
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer)	{
		loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL){
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
			if (newTexture == NULL)	{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);

		}//must return something
		return newTexture;
	}
	void move(){

	}
}

#endif

