#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Memory.h"
#include "../include/Display.h"
#include "../include/CPU.h"
#include "../include/Platform.h"
#include "../include/Keypad.h"

#define FPS 1000
#define frameDelay 1000 / FPS


int main(){
 
    Memory memory;
    Display display;
    Keypad keypad;
    CPU cpu(memory, display, keypad);
    Platform platform("CHIP8-Emulator", VIDEO_WIDTH*PIXEL_SIZE, VIDEO_HEIGHT*PIXEL_SIZE, VIDEO_WIDTH, VIDEO_HEIGHT);
    
    std::string romPath = "../roms/games/pong.ch8";
    memory.loadROM(romPath);

    bool running = true;
    SDL_Event event;

    while(running){

        uint32_t frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;  // Close windows
            }
            else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {

                bool pressed = event.type == SDL_KEYDOWN;
                SDL_Keycode keycode = event.key.keysym.sym;

                if (platform.getKeymap().count(keycode)) {
                    uint8_t chip8Key = platform.getKeymap().at(keycode);
                    keypad.setKey(chip8Key, pressed);
                }

                if (pressed && keycode == SDLK_ESCAPE) {
                    running = false;  // Escape
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



