#pragma once

#include <iostream>

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include <SDL_image.h>

class Osa {
public:
	std::string OSA_VERSION = "Osa v1.0.0";
	int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

	Osa(std::string title, int width, int height);

	void update();
	void render();

private:
	bool run = false;
	SDL_Window* window;
	SDL_GLContext context;
};