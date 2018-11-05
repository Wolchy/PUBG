#include "Osa.h"

Screen* Osa::screen = NULL;
Screen* Osa::debugScreen = NULL;

bool Osa::init(std::string title, int width, int height){
	std::cout << "Starting " << OSA_VERSION << std::endl;

	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	return run;
}

void Osa::loop() {
	update();
	render();
}

void Osa::update() {
	if (screen != NULL)
		screen->update();
}

void Osa::render() {
	fps.update();
}

bool Osa::isRunning() {
	return run;
}

void Osa::exit() {
	run = false;
}
