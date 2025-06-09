#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Memory.h"
#include "../include/Display.h"
#include "../include/CPU.h"
#include "../include/Platform.h"


int main(){
 
    std::string romPath = "../roms/test2.ch8";

    
    Memory memory;
    Display display;

    memory.loadROM(romPath);
    CPU cpu(memory, display);
    

    
    Platform platform("CHIP8-Emulator", VIDEO_WIDTH*PIXEL_SIZE, VIDEO_HEIGHT*PIXEL_SIZE, VIDEO_WIDTH, VIDEO_HEIGHT);
    
    const int FPS = 10;
    const int frameDelay = 1000 / FPS;


    bool running = true;
    SDL_Event event;


    while(running){

        uint32_t frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;  // Cerrar ventana
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;  // Salir con ESC
            }
        }
    }

        
        cpu.clockCycle();
        platform.Update(display.getBuffer(), VIDEO_WIDTH * sizeof(uint32_t));

        uint32_t frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}

