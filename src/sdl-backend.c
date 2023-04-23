#include "gfx.h"

#include <SDL2/SDL.h>
#include <stdio.h>

struct SdlContext {
	SDL_Window* window;
	SDL_Renderer* renderer;
	u8 shouldClose;
	SDL_Event event;
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

