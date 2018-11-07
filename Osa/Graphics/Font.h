#pragma once

#include <iostream>
#include <map>

#include <SDL_opengl.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm.hpp>

struct Character {
	GLuint		TextureID;
	glm::ivec2	Size;
	glm::ivec2	Bearing;
	GLuint		Advance;
};

class Font {
public:
	std::map<GLchar, Character> Characters;

	Font(std::string path);
};