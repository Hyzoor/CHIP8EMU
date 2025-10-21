#include "../include/Display.h"
#include "Display.h"
#include <SDL2/SDL.h>

Display::Display() {}
Display::~Display() {}

Display::Display(SDL_Renderer *renderer) {
	this->renderer = renderer;
}

uint32_t Display::getPixel(uint8_t x, uint8_t y) {
	return screenBuffer[(y * VIDEO_WIDTH) + x];
}

void Display::setPixel(uint8_t x, uint8_t y, uint32_t value) {
	screenBuffer[(y * VIDEO_WIDTH) + x] = value;
}

void Display::clearBuffer() {
	memset(screenBuffer, 0, sizeof(screenBuffer));
}

uint8_t Display::getHeight() {
	return VIDEO_HEIGHT;
}

uint8_t Display::getWidth() {
	return VIDEO_WIDTH;
}

uint8_t *Display::getBuffer() {
	return screenBuffer;
}