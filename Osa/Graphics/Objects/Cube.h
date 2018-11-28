#pragma once

#include "../Texture.h"
#include "../Shader.h"

class Cube {
public:
	Shader* shader;
	Texture* tex;
	unsigned int VBO, VAO;

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	
	Cube(std::string texturePath, std::string shaderPath);

	void render();
};