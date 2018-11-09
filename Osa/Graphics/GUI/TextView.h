#pragma once

#include <glm.hpp>
#include <map>

#include "../Shader.h"
#include "../Font.h"

class TextView {
public:
	float x = 0.0f, y = 0.0f;

	TextView(std::string _text, float _x, float _y, float _scale, glm::vec3 _color, Shader &_shader, Font* _font);

	void render();

private:
	Shader* shader;
	glm::vec3 color;
	std::string text;
	float scale;
	Font* font;
	GLuint VBO, VAO;
};