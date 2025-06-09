#ifndef DISPLAY_H
#define DISPLAY_H
#include <cstdint>
#include <SDL2/SDL.h>

#define PIXEL_SIZE 16
#define VIDEO_WIDTH 64
#define VIDEO_HEIGHT 32



class Display{

public:


    Display(SDL_Renderer* renderer);
    Display();
    ~Display();

    uint32_t getPixel(uint8_t, uint8_t);
    void setPixel(uint8_t x, uint8_t y, uint32_t value);
    void clearBuffer();

    uint8_t getHeight();
    uint8_t getWidth();
    uint32_t* getBuffer();



private:

    SDL_Renderer* renderer;
    uint32_t screenBuffer[VIDEO_WIDTH * VIDEO_HEIGHT]{}; 

};



#endif