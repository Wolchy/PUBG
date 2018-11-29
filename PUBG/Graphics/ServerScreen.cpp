#include "ServerScreen.h"

ServerScreen::ServerScreen() : Screen::Screen("serverScreen"){
}

void ServerScreen::update(Osa* osa){
	if (!init) {
		if (SDL_GL_SetSwapInterval(1) < 0) {
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}
		init = true;
		network.init(*osa);
	}
	else {
		network.update();
	}
}

void ServerScreen::render(Osa* osa)
{

}
