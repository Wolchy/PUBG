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
#include <gtc/type_ptr.hpp>
#include <SDL_net.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stb_image.h>

class Screen;
#include "Util/FPS.h"
#include "Lua/Lua.h"

class Osa {
public:
	std::string OSA_VERSION = "Osa v1.1.0";
	int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

	FPS fps;
	double deltaTime = 0.0f;
	Lua* lua = NULL;

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
	SDL_Window* getWindow();
	int getScreenWidth();
	int getScreenHeight();
	double getDelta();
	int getFPS();
	std::string getVersion();
	Osa* getOsa();

private:
	static bool run;
	static bool server;

	SDL_Window* window;
	SDL_GLContext context;

	static Screen* screen;
	static Screen* serverScreen;

	double delta_last = 0.0f, delta_current = 0.0f;
};