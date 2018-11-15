#pragma once

#include "../../Osa/Graphics/GUI/Screen.h"

class ServerScreen : public Screen {
public:
	ServerScreen();
	
	virtual void update(Osa osa);
	virtual void render(Osa osa);
};