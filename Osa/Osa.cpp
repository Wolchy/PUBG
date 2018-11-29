#include "Osa.h"

#include "Graphics/GUI/Screen.h"

Screen* Osa::screen = NULL;
Screen* Osa::serverScreen = NULL;

bool Osa::run = false;
bool Osa::server = false;

bool Osa::init(std::string title, int width, int height) {
	std::cout << "Starting " << OSA_VERSION << std::endl;

	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		if (SDLNet_Init() != -1) {
			if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) {
				if (TTF_Init() != -1) {
					window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
					if (window != NULL) {
						SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
						SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
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
							glEnable(GL_DEPTH_TEST);
							glLoadIdentity();
							SDL_SetWindowIcon(window, IMG_Load("speedy boi.jpg"));
							SDL_SetThreadPriority(SDL_THREAD_PRIORITY_HIGH);

							lua = new Lua();
							lua->loadOsa(this);
							lua->loadUtil();
							lua->loadFileSystem();
							lua->loadGraphics();
							lua->loadNetwork();

							std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << std::endl;

							run = true;
						} else {
							std::cout << "context == NULL: " << SDL_GetError() << std::endl;
						}
					} else {
						std::cout << "window == NULL: " << SDL_GetError() << std::endl;
					}
				} else {
					std::cout << "Error: Osa::init: TTF: " << TTF_GetError() << std::endl;
				}
			} else {
				std::cout << "Error: Osa::init: IMG: " << IMG_GetError() << std::endl;
			}
		} else {
			std::cout << "Error: Osa::init: SDLNet: " << SDLNet_GetError() << std::endl;
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
			serverScreen->update(this);
	}
	else
		if (screen != NULL)
			screen->update(this);

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
					serverScreen->keyUp(this, e.key.keysym.sym);
			}
			else
				if (screen != NULL)
					screen->keyUp(this, e.key.keysym.sym);
		}
		else if (e.type == SDL_KEYDOWN) {
			if (server) {
				if (serverScreen != NULL)
					serverScreen->keyDown(this, e.key.keysym.sym);
			}
			else
				if (screen != NULL)
					screen->keyDown(this, e.key.keysym.sym);
		}
		else if (e.type == SDL_MOUSEMOTION) {
			int x, y, xx = 0, yy = 0;
			SDL_GetMouseState(&x, &y);
			x = e.motion.xrel;
			y = e.motion.yrel;
			if (server) {
				if (serverScreen != NULL) {
					serverScreen->mouseMoved(this, x, y);
					serverScreen->mousePos(this, xx, yy);
				}
			}
			else
				if (screen != NULL) {
					screen->mouseMoved(this, x, y);
					screen->mousePos(this, xx, yy);
				}
		}
	}
}

void Osa::render() {
	delta_last = delta_current;
	delta_current = SDL_GetPerformanceCounter();
	deltaTime = (double)((delta_current - delta_last) * 1000 / SDL_GetPerformanceFrequency());

	if (difftime(time(0), fps.start) >= 1) {
		std::string fuckYouMom = "FPS: " + std::to_string(fps.fps) + " Delta: " + std::to_string(deltaTime);
		SDL_SetWindowTitle(window, fuckYouMom.c_str());
	}

	fps.update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (server) {
		if (serverScreen != NULL)
			serverScreen->render(this);
	}
	else
		if (screen != NULL)
			screen->render(this);
	
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

Screen * Osa::getScreen()
{
	return screen;
}

Screen * Osa::getServerScreen()
{
	return serverScreen;
}

bool Osa::isRunning() {
	return run;
}

bool Osa::isServer()
{
	return server;
}

void Osa::exit() {
	run = false;
}

SDL_Window * Osa::getWindow()
{
	return window;
}

int Osa::getScreenWidth()
{
	return SCREEN_WIDTH;
}

int Osa::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

double Osa::getDelta()
{
	return deltaTime;
}

int Osa::getFPS()
{
	return fps.fps;
}

std::string Osa::getVersion()
{
	return OSA_VERSION;
}

Osa * Osa::getOsa()
{
	return this;
}
