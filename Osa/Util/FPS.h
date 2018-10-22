#pragma once

#include <time.h>

class FPS {
public:
	int fps = 0;

	FPS();
	void update();

private:
	time_t start;
	int frames = 0;
};