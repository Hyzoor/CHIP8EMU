#include "Platform.h"
#include "Display.h"

constexpr uint32_t PixelON = 0xFDCE4EFF;
constexpr uint32_t PixelOFF = 0x000000FF;

Platform::Platform(char const *title, int windowWidth, int windowHeight, int textureWidth, int textureHeight) {
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, textureWidth, textureHeight);

	keymap = {{SDLK_1, 0x1}, {SDLK_2, 0x2}, {SDLK_3, 0x3}, {SDLK_4, 0xC}, {SDLK_q, 0x4}, {SDLK_w, 0x5}, {SDLK_e, 0x6}, {SDLK_r, 0xD}, {SDLK_a, 0x7}, {SDLK_s, 0x8}, {SDLK_d, 0x9}, {SDLK_f, 0xE}, {SDLK_z, 0xA}, {SDLK_x, 0x0}, {SDLK_c, 0xB}, {SDLK_v, 0xF}};
}

Platform::~Platform() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Platform::Update(uint8_t *buffer) {
	static uint32_t pixels[VIDEO_WIDTH * VIDEO_HEIGHT];

	for (int y = 0; y < VIDEO_HEIGHT; y++) {
		for (int x = 0; x < VIDEO_WIDTH; x++) {
			pixels[y * VIDEO_WIDTH + x] = buffer[y * VIDEO_WIDTH + x] ? PixelON : PixelOFF;
		}
	}

	SDL_UpdateTexture(texture, nullptr, pixels, VIDEO_WIDTH * sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
}

const std::map<SDL_Keycode, uint8_t> &Platform::getKeymap() {
	return keymap;
}
