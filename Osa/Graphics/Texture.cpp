#include "Texture.h"

#include <stb_image.h>

Texture::Texture(std::string texturePath) {
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(texturePath.c_str(), &w, &h, &nrChannels, 0);
	if (data) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}