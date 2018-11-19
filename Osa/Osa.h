#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#undef main
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <SDL_net.h>

class Screen;
#include "Util/FPS.h"

class Osa {
public:
	std::string OSA_VERSION = "Osa v1.1.0";
	int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

	FPS fps;

	bool init(std::string title, int width, int height);

	void loop();
	void update();
	void render();

	void setScreen(Screen* screen);
	void setServerScreen(Screen* screen);
	void setServer(bool _isServer);

	Screen* getScreen();
	Screen* getServerScreen();

	bool isRunning();
	bool isServer();
	void exit();

private:
	static bool run;
	static bool server;

	SDL_Window* window;
	SDL_GLContext context;

	static Screen* screen;
	static Screen* serverScreen;
};