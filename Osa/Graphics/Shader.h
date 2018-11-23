#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

class Shader {
public:
	unsigned int ID;

	Shader(std::string vertex, std::string fragment, bool);

	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};