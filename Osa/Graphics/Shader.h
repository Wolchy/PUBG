#pragma once

#include <iostream>

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

#include "../File/File.h"

class Shader {
public:
	unsigned int ID;

	Shader(std::string vertexPath, std::string fragmentPath);

	void use();
	//setBool
	//setInt
	//setFloat
};