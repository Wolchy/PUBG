#include "TestScreen.h"

TestScreen::TestScreen() : Screen::Screen("testScreen"){

}

void TestScreen::update(Osa* osa) {
	float cameraSpeed = speed * osa->deltaTime;
	if(w)
		cameraPos += cameraSpeed * cameraFront;
	if(s)
		cameraPos -= cameraSpeed * cameraFront;
	if(a)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if(d)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if (console) {
		console = false;
		std::string consoleBuffer;
		std::getline(std::cin, consoleBuffer);

		osa->lua->exec(consoleBuffer);
	}
	if (init)
		network.update();
}

void TestScreen::render(Osa* osa) {
	if (!rInit) {
		for (unsigned int i = 0; i < 10; i++) {
			cubes[i] = new Cube("sofia carson.png", "basic");
		}
		rInit = true;
	}
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glm::mat4 projection = glm::perspective(glm::radians(fov), (float)osa->SCREEN_WIDTH / (float)osa->SCREEN_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	// render boxes
	for (unsigned int i = 0; i < 10; i++) {
		glm::mat4 model(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

		cubes[i]->model = model;
		cubes[i]->view = view;
		cubes[i]->projection = projection;
		cubes[i]->render();
	}
}

void TestScreen::keyUp(Osa* osa, SDL_Keycode key) {
	if (key == SDLK_BACKQUOTE)
		console = true;
	if (key == SDLK_ESCAPE)
		osa->exit();
	if (key == SDLK_F1) {
		if (SDL_GetWindowGrab(osa->getWindow())) {
			SDL_SetRelativeMouseMode(SDL_FALSE);
			SDL_WarpMouseInWindow(osa->getWindow(), osa->SCREEN_WIDTH / 2, osa->SCREEN_HEIGHT / 2);
		}
		else {
			SDL_SetRelativeMouseMode(SDL_TRUE);
		}
	}
	if (key == SDLK_F2) {
		if (SDL_GL_GetSwapInterval() == 1){
			if (SDL_GL_SetSwapInterval(0) < 0) {
				printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			}
		}
		else
			if (SDL_GL_SetSwapInterval(1) < 0) {
				printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			}
	}

	if (key == SDLK_w)
		w = false;
	if (key == SDLK_s)
		s = false;
	if (key == SDLK_a)
		a = false;
	if (key == SDLK_d)
		d = false;
}

void TestScreen::keyDown(Osa* osa, SDL_Keycode key) {
	if (key == SDLK_w)
		w = true;
	if (key == SDLK_s)
		s = true;
	if (key == SDLK_a)
		a = true;
	if (key == SDLK_d)
		d = true;
}

void TestScreen::mouseMoved(Osa* osa, int x, int y){
	if (SDL_GetWindowGrab(osa->getWindow())) {
		float offsetX = x;
		float offsetY = y;
		offsetX *= sensitivity/10;
		offsetY *= sensitivity/10;
		yaw += offsetX;
		pitch -= offsetY;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(front);
	}
}
