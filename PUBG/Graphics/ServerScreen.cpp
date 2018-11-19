#include "ServerScreen.h"

ServerScreen::ServerScreen() : Screen::Screen("serverScreen"){

}

void ServerScreen::update(Osa osa){
	if (!init) {
		init = true;
		network.init(osa);
	}
	else {
		network.update();
	}
}

void ServerScreen::render(Osa osa)
{

}
