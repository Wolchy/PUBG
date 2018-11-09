#pragma once

#include <time.h>

class FPS {
public:
	int fps = 0;
	time_t start;

	FPS();
	void update();

private:
	int frames = 0;
};