#pragma once

class Screen {
public:
	Screen();

	virtual void update();
	virtual void render();

	virtual void keyup(SDL_Keycode);
};