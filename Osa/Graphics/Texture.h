#pragma once

#include <iostream>
#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

class Texture {
public:
	GLuint id = 0;
	int w = 0, h = 0;

	Texture(std::string texturePath);
	int getID();
	int getWidth();
	int getHeight();
};