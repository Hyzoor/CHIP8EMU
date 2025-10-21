#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <map>

class Platform {

  public:
	Platform(char const *title, int winWidth, int winHeight, int textureWidth, int textureHeight);
	~Platform();

	void Update(uint8_t *buffer);
	const std::map<SDL_Keycode, uint8_t> &getKeymap();

  private:
	std::map<SDL_Keycode, uint8_t> keymap;
	SDL_Window *window{};
	SDL_Renderer *renderer{};
	SDL_Texture *texture{};
};

#endif