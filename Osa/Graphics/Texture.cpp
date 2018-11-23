#include "Texture.h"

Texture::Texture(std::string texturePath) {
	SDL_Surface* surface = IMG_Load(texturePath.c_str());
	if (surface != NULL) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		int mode = GL_RGB;
		if (surface->format->BitsPerPixel == 4)
			mode = GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		w = surface->w;
		h = surface->h;
	} else {
		std::cout << "Error: Texture: IMG: " << IMG_GetError() << std::endl;
	}
}

Texture::Texture(SDL_Surface * surface) {
	if (surface != NULL) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		int mode = GL_RGB;
		if (surface->format->BitsPerPixel == 4)
			mode = GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else {
		std::cout << "Error: Texture: surface is null" << std::endl;
	}
}
