#ifndef DISPLAY_H
#define DISPLAY_H
#include <cstdint>
#include <SDL2/SDL.h>

#define PIXEL_SIZE 16
#define VIDEO_WIDTH 64
#define VIDEO_HEIGHT 32



class Display{

public:
    bool screenBuffer[VIDEO_WIDTH][VIDEO_HEIGHT]; 


    Display(SDL_Renderer* renderer);
    Display();
    ~Display();

    bool getPixel(uint8_t, uint8_t);
    void setPixel(uint8_t, uint8_t, bool value);
    void clearBuffer();
    void drawScreen();

    uint8_t getHeight();
    uint8_t getWidth();

private:


    SDL_Renderer* renderer;


};











#endif