#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../../Osa/Graphics/GUI/Screen.h"
#include "../../Osa/Util/SplitString.h"
#include "../../Osa/Network/Network.h"
#include "../../Osa/Graphics/Shader.h"
#include "../../Osa/Graphics/Texture.h"
#include "../../Osa/Graphics/Objects/Cube.h"

//TODO make camera class

class TestScreen : public Screen {
public:
	bool console = false;
	bool init = false;
	Network network;
	bool rInit = false;

	Cube* cubes[10];

	//MA GRAB THE CAMERA
	bool w = false, s = false, a = false, d = false;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	bool firstMouse = true;
	float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch = 0.0f;
	float fov = 75.0f;
	float sensitivity = 1.0f;
	float speed = 0.01f;

	TestScreen();

	virtual void update(Osa* osa);
	virtual void render(Osa* osa);

	virtual void keyUp(Osa* osa, SDL_Keycode key);
	virtual void keyDown(Osa* osa, SDL_Keycode key);
	virtual void mouseMoved(Osa*, int, int);
};