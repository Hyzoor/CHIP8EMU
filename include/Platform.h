#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>


class Platform{

    public:

    Platform(char const*, int , int , int , int);
    ~Platform();

    void Update(void const*, int);

    private:
	SDL_Window* window{};
	SDL_Renderer* renderer{};
	SDL_Texture* texture{};

};

#endif