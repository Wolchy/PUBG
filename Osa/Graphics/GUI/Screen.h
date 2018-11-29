#pragma once

#include <iostream>
#include <SDL.h>

#include "../../Osa.h"

class Screen {
public:
	int mouseX, mouseY;
	std::string id;
	Screen(std::string);

	virtual void update(Osa*);
	virtual void render(Osa*);

	virtual void resize(Osa*);
	virtual void keyDown(Osa*, SDL_Keycode);
	virtual void keyUp(Osa*, SDL_Keycode);
	virtual void mouseKeyUp(Osa*, SDL_MouseButtonEvent&);
	virtual void mouseKeyDown(Osa*, SDL_MouseButtonEvent&);
	virtual void mouseScroll(Osa*, SDL_MouseWheelEvent&);
	virtual void mouseMoved(Osa*, int, int);
	virtual void mousePos(Osa*, int, int);
	virtual void event(Osa*, SDL_Event);

private:
};