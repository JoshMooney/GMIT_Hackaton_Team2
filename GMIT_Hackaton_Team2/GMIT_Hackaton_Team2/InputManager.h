#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <tuple>

using std::tuple;
using std::make_tuple;

class InputManager {
private:
	enum directions { LEFT, RIGHT, UP, ACTION };
	enum gameKeys { RESET, QUIT, FFW, CLICK };
	int mouse_x;
	int mouse_y;
	bool gameOutput[3];
	bool playerOutput[4];

	void clearInputs();
public:
	InputManager();

	int getX() { return mouse_x;}
	int getY() { return mouse_y;}

	tuple<bool, bool, bool, bool> getPlayerKeys() const;
	tuple<bool, bool, bool, bool> getGameKeys() const;

	void update();
};

#endif