#pragma once

#include <iostream>
#include <string>

#include "../../Osa/Graphics/GUI/Screen.h"
#include "../../Osa/Util/SplitString.h"
#include "../../Osa/Network/Network.h"

#include "../../Osa/Graphics/Shader.h"
#include "../../Osa/Graphics/Texture.h"

class TestScreen : public Screen {
public:
	bool console = false;
	bool init = false;
	Network network;

	TestScreen();

	virtual void update(Osa osa);
	virtual void render(Osa osa);

	virtual void keyUp(Osa osa, SDL_Keycode key);
};