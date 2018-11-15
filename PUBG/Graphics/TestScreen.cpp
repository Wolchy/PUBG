#include "TestScreen.h"

TestScreen::TestScreen() : Screen::Screen("testScreen"){}

void TestScreen::update(Osa osa)
{
	if (console) {
		console = false;
		std::string consoleBuffer;
		std::getline(std::cin, consoleBuffer);

		//osa.lua.exec(consoleBuffer);
	}
}

void TestScreen::keyUp(Osa osa, SDL_Keycode key)
{
	if (key == SDLK_BACKQUOTE)
		console = true;
}
