#include "../include/Display.h"
#include <SDL2/SDL.h>
#include "Display.h"


Display::Display(){}
Display::~Display(){}

Display::Display(SDL_Renderer* renderer){
    this->renderer = renderer;
}

bool Display::getPixel(uint8_t x, uint8_t y){
    return screenBuffer[x][y];
}

void Display::setPixel(uint8_t x, uint8_t y, bool value){
    screenBuffer[x][y] = value;
}

void Display::clearBuffer(){
    for(int i=0; i < VIDEO_WIDTH; i++){
        for(int j=0; j < VIDEO_HEIGHT; j++){
            screenBuffer[i][j] = false;
        }
    }
}

void Display::drawScreen(){


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int y = 0; y < VIDEO_HEIGHT; ++y) {
        for (int x = 0; x < VIDEO_WIDTH; ++x) {
            if (screenBuffer[x][y]) {
                SDL_Rect pixel = { x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE };
                SDL_RenderFillRect(renderer, &pixel);
                SDL_RenderPresent(renderer);

            }
        }
    }

}

uint8_t Display::getHeight(){
    return VIDEO_HEIGHT;
}

uint8_t Display::getWidth(){
    return VIDEO_WIDTH;
}