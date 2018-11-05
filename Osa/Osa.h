#pragma once

#include <iostream>
#include <string>
#include <time.h>

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
	bool run = false;
	time_t timer;

	static Screen* screen;
	static Screen* debugScreen;
};