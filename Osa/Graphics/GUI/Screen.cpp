#include "Screen.h"

Screen::Screen(std::string i) {
	id = i;
}

void Screen::update(Osa* osa) {}
void Screen::render(Osa*) {}

void Screen::resize(Osa*) {}
void Screen::keyDown(Osa*, SDL_Keycode keycode) {}
void Screen::keyUp(Osa*, SDL_Keycode keycode) {}
void Screen::mouseKeyUp(Osa*, SDL_MouseButtonEvent &event) {}
void Screen::mouseKeyDown(Osa*, SDL_MouseButtonEvent &event) {}
void Screen::mouseScroll(Osa*, SDL_MouseWheelEvent &) {}
void Screen::mouseMoved(Osa*, int x, int y) {}

void Screen::mousePos(Osa *, int x, int y)
{
	mouseX = x;
	mouseY = y;
}

void Screen::event(Osa*, SDL_Event event) {}
