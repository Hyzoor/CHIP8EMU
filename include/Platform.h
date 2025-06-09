#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <map>


class Platform{

    public:

    Platform(char const* title, int winWidth , int winHeight , int textureWidth , int textureHeight);
    ~Platform();

    void Update(void const* buffer, int pitch);
    const std::map<SDL_Keycode, uint8_t>& getKeymap();

    private:
    std::map<SDL_Keycode, uint8_t> keymap;
	SDL_Window* window{};
	SDL_Renderer* renderer{};
	SDL_Texture* texture{};

};

#endif