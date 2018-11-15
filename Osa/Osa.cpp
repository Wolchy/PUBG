#include "Osa.h"

#include "Graphics/GUI/Screen.h"

Screen* Osa::screen = NULL;
Screen* Osa::serverScreen = NULL;

bool Osa::run = false;
bool Osa::server = false;

bool Osa::init(std::string title, int width, int height){
	std::cout << "Starting " << OSA_VERSION << std::endl;

	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
		if (window != NULL) {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

			context = SDL_GL_CreateContext(window);
			if (context != NULL) {
				glewExperimental = true;
				GLenum err = glewInit();

				glClearColor(0.0, 0.0, 0.0, 1.0);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glViewport(0, 0, width, height);
				gluPerspective(75.0, width / height, 0.0f, 100.0);
				glMatrixMode(GL_MODELVIEW);
				glEnable(GL_BLEND);
				glLoadIdentity();

				std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << std::endl;

				run = true;
			}
			else {
				std::cout << "context == NULL: " << SDL_GetError() << std::endl;
			}
		}
		else {
			std::cout << "window == NULL: " << SDL_GetError() << std::endl;
		}
	}

	return run;
}

void Osa::loop() {
	update();
	render();
}

void Osa::update() {
	SDL_Event e;

	if (server) {
		if (serverScreen != NULL)
			serverScreen->update(*this);
	}
	else
		if (screen != NULL)
			screen->update(*this);

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			exit();
		}
		else if (e.type == SDL_WINDOWEVENT) {
			SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
			glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			gluPerspective(75.0, SCREEN_WIDTH / SCREEN_HEIGHT, 0.0f, 100.0);
		}
		else if (e.type == SDL_KEYUP) {
			if (server) {
				if (serverScreen != NULL)
					serverScreen->keyUp(*this, e.key.keysym.sym);
			}
			else
				if (screen != NULL)
					screen->keyUp(*this, e.key.keysym.sym);
		}
	}
}

void Osa::render() {
	if (difftime(time(0), fps.start) >= 1)
		SDL_SetWindowTitle(window, std::to_string(fps.fps).c_str());

	fps.update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (server) {
		if (serverScreen != NULL)
			serverScreen->render(*this);
	}
	else
		if (screen != NULL)
			screen->render(*this);
	
	SDL_GL_SwapWindow(window);
}

void Osa::setScreen(Screen * _screen) {
	screen = _screen;
}

void Osa::setServerScreen(Screen * screen) {
	serverScreen = screen;
}

void Osa::setServer(bool _isServer) {
	server = _isServer;
}

bool Osa::isRunning() {
	return run;
}

void Osa::exit() {
	run = false;
}
