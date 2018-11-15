#pragma once

#include <iostream>
#include <string>

#include "../../Osa/Graphics/GUI/Screen.h"
#include "../../Osa/Util/SplitString.h"

class TestScreen : public Screen {
public:
	bool console = false;

	TestScreen();

	virtual void update(Osa osa);

	virtual void keyUp(Osa osa, SDL_Keycode key);
};