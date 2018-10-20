#pragma once

#include <iostream>

class Osa {
public:
	std::string OSA_VERSION = "Osa v2.0.0";
	int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;

	Osa(std::string title, int width, int height);

	void update();
	void render();

private:

};