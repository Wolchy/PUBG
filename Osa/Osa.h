#pragma once

#include <iostream>
#include <string>
#include <time.h>

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

#include "Util/FPS.h"
#include "Graphics/GUI/Screen.h"

class Osa {
public:
	std::string OSA_VERSION = "Osa v1.1.0";
	int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

	FPS fps;

	bool init(std::string title, int width, int height);

	void loop();
	void update();
	void render();

	bool isRunning();
	void exit();

private:
	static bool run;
	time_t timer;

	static SDL_Window* window;
	static SDL_GLContext context;

	static Screen* screen;
	static Screen* debugScreen;
};