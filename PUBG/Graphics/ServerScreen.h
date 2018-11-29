#pragma once

#include "../../Osa/Graphics/GUI/Screen.h"

#include "../../Osa/Network/Network.h"

class ServerScreen : public Screen {
public:
	Network network;
	bool init = false;

	ServerScreen();
	
	virtual void update(Osa* osa);
	virtual void render(Osa* osa);
};