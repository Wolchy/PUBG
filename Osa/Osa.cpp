#include "Osa.h"

Osa::Osa(std::string title, int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << "SDL could not init! Error: " << SDL_GetError() << std::endl;
	}
	else {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (window == NULL) {
			std::cout << "Window could not be created! Error: " << SDL_GetError() << std::endl;
		}
		else {
			context = SDL_GL_CreateContext(window);
			if (context == NULL) {
				std::cout<<"OpenGL context could not be created! Error: " << SDL_GetError() << std::endl;
			}
			else {
				glewExperimental = GL_TRUE;
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK) {
					std::cout << "Error init GLEW! Error: " << glewGetErrorString(glewError) << std::endl;
				}
				else {
					GLenum error = GL_NO_ERROR;

					GLuint VertexArrayID;
					glGenVertexArrays(1, &VertexArrayID);
					glBindVertexArray(VertexArrayID);

					glDepthFunc(GL_LESS);
					glEnable(GL_DEPTH_TEST);
					glEnable(GL_CULL_FACE);

					glLoadIdentity();
					error = glGetError();
					if (error != GL_NO_ERROR) {
						std::cout << "Error init OpenGL! Error: " << gluErrorString(error) << std::endl;
					}
					else {
						run = true;
					}
				}
			}
		}
	}
}

void Osa::update()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			run = false;
		}
		if (e.type == SDL_WINDOWEVENT) {
			glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 1.0, 100.0);
			glMatrixMode(GL_MODELVIEW);
			if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
				SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
				
			}
		}
	}
}

void Osa::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();



	glFlush();
	SDL_GL_SwapWindow(window);
}
