#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Memory.h"
#include "../include/Display.h"
#include "../include/CPU.h"
#include "../include/Platform.h"


int main(){
 

    
    Memory memory;
    Display display;

    std::string romPath = "../roms/test1.ch8";
    memory.loadROM(romPath);

    Platform platform("CHIP8-Emulator", VIDEO_WIDTH*PIXEL_SIZE, VIDEO_HEIGHT*PIXEL_SIZE, VIDEO_WIDTH, VIDEO_HEIGHT);

    CPU cpu(memory, display);

    while(true){

        cpu.clockCycle();
        platform.Update(display.screenBuffer,16);
    }

    return 0;
}

