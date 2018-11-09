#include "Osa.h"

bool Osa::run = false;

Screen* Osa::screen = NULL;
Screen* Osa::debugScreen = NULL;

SDL_Window* Osa::window = NULL;
SDL_GLContext Osa::context = NULL;

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
				gluPerspective(60.0, width / height, 0.1, 100.0);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << std::endl;

				glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

				std::string p = SDL_GetBasePath();
				Font* f = new Font(p + "font.ttf");
				Shader s = Shader(p + "font.vertex", p + "font.fragment");
				tv = new TextView("test", 50.f, 50.f, 1.f, glm::vec3(.5f, .5f, .5f), s, f);

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

	if (screen != NULL)
		screen->update();

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			exit();
		}
		else if (e.type == SDL_WINDOWEVENT) {
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, SCREEN_WIDTH / SCREEN_HEIGHT, 1.0, 500.0);
			glMatrixMode(GL_MODELVIEW);
			glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
			glLoadIdentity();
		}
	}
}

void Osa::render() {
	if (difftime(time(0), fps.start) >= 1)
		SDL_SetWindowTitle(window, std::to_string(fps.fps).c_str());
	fps.update();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (screen != NULL)
		screen->render();

	
	tv->render();
	
	SDL_GL_SwapWindow(window);
}

bool Osa::isRunning() {
	return run;
}

void Osa::exit() {
	run = false;
}
