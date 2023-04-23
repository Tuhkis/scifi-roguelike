#include "gfx.h"

#include <SDL2/SDL.h>
#include <stdio.h>

#include "fps.h"

struct SdlContext {
	SDL_Window* window;
	SDL_Renderer* renderer;
	u8 shouldClose;
	SDL_Event event;
	u64 now, prev;
	SDL_Texture* textures[TEXURES_LEN];
}; struct SdlContext context = { 0 };

void openDisplay() {
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("%s\n", "Couldn't intialise SDL2 ):");		
	}
	context.window = SDL_CreateWindow(W_TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
	context.renderer = SDL_CreateRenderer(context.window, 0, SDL_RENDERER_ACCELERATED);
	context.shouldClose = 0;
}

void pollEvents() {
	while( SDL_PollEvent( &context.event ) != 0 ) {
		switch (context.event.type) {
			case SDL_QUIT:
				context.shouldClose = 1;
				break;
			default:
				break;
		}
	}
}

u8 shouldClose() {
	return context.shouldClose;
}

void clearScreen(u8 r, u8 g, u8 b) {
	SDL_SetRenderDrawColor(context.renderer, r, g, b, 255);
	SDL_RenderClear(context.renderer);
}

void display() {
	SDL_RenderPresent(context.renderer);
}

void cleanGfx() {
	SDL_DestroyRenderer(context.renderer);
	SDL_DestroyWindow(context.window);
}

float tick(u16 fps) {
	context.now = SDL_GetPerformanceCounter();
	SDL_Delay(1000 / 60);
	float dt = (context.now - context.prev) / (float)SDL_GetPerformanceFrequency();
	context.prev = context.now;
	return dt;
}

void drawRect(i32 x, i32 y, u16 w, u16 h, u8 r, u8 g, u8 b) {
	SDL_SetRenderDrawColor(context.renderer, r, g, b, 255);
	SDL_RenderFillRect(context.renderer, &(SDL_Rect) {x, y, w, h});
}

void loadTextureToIndex(u8 w, u8 h, const u8 data[], u8 index) {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	for (u8 y = 0; y < h; ++y) {
		for (u8 x = 0; x < w; ++x) {
			int p = (y*w+x)*3;
			u32 colour =
				(255 << 24) | (data[p] << 16) | ( data[p+1] << 8 ) | (data[p+2]);
			// printf("COL: %x\n", colour);
			SDL_FillRect(surface,
				&(SDL_Rect) {x, y, 1, 1},
				colour);
		}
	}
	context.textures[index] = SDL_CreateTextureFromSurface(context.renderer, surface);
}

void drawTexture(i32 x, i32 y, u8 w, u8 h, u8 index) {
	SDL_RenderCopy(context.renderer, context.textures[index], NULL, &(SDL_Rect) {x, y, w, h});
}

