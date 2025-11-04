#include <SDL2/SDL.h>

#include <iostream>

#include "CPU.h"
#include "Display.h"
#include "Keypad.h"
#include "Memory.h"
#include "Platform.h"

#define FPS 60
#define CPU_HZ 500
#define CYCLES_PER_FRAME (CPU_HZ / FPS)
#define FRAME_DELAY 1000 / FPS

int main() {
	Memory memory;
	Display display;
	Keypad keypad;
	CPU cpu(memory, display, keypad);
	Platform platform("CHIP8-Emulator", VIDEO_WIDTH * PIXEL_SIZE, VIDEO_HEIGHT * PIXEL_SIZE, VIDEO_WIDTH, VIDEO_HEIGHT);

	std::string romPath = "../roms/testFlags.ch8";
	memory.loadROM(romPath);

	bool running = true;
	SDL_Event event;

	while (running) {
		uint32_t frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false; // Close windows
			} else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
				bool pressed = event.type == SDL_KEYDOWN;
				SDL_Keycode keycode = event.key.keysym.sym;

				if (platform.getKeymap().count(keycode)) {
					uint8_t chip8Key = platform.getKeymap().at(keycode);
					keypad.setKey(chip8Key, pressed);
				}

				if (pressed && keycode == SDLK_ESCAPE) {
					running = false; // Escape
				}
			}
		}

		for (int i = 0; i < CYCLES_PER_FRAME; i++) {
			cpu.clockCycle();
		}

		platform.Update(display.getBuffer());
		cpu.updateTimers();

		uint32_t frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	return 0;
}
