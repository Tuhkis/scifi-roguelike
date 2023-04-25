#include "gfx.h"
#include "fps.h"
#include "input.h"

#include <SDL2/SDL.h>
#include <stdio.h>

struct SdlContext {
	SDL_Window* window;
	SDL_Renderer* renderer;
	u8 shouldClose;
	SDL_Event event;
	u64 now, prev;
	SDL_Texture* textures[TEXURES_LEN];
	Input input;
}; struct SdlContext context = { 0 };

void openDisplay() {
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("%s\n", "Couldn't initialise SDL2 ):");		
	}
	context.window = SDL_CreateWindow(W_TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
	#ifdef VSYNC
	context.renderer = SDL_CreateRenderer(context.window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	#else
	context.renderer = SDL_CreateRenderer(context.window, 0, SDL_RENDERER_ACCELERATED);
	#endif
	context.shouldClose = 0;
}

#define KEY(a, b, c) \
	case a:\
		b = c;\
		break

void handleInput() {
	switch (context.event.type) {
		case SDL_KEYDOWN:
			switch (context.event.key.keysym.sym) {
				KEY(SDLK_a, context.input.mLeft,  1);
				KEY(SDLK_d, context.input.mRight, 1);
				KEY(SDLK_w, context.input.mUp,    1);
				KEY(SDLK_s, context.input.mDown,  1);

				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch (context.event.key.keysym.sym) {
				KEY(SDLK_a, context.input.mLeft,  0);
				KEY(SDLK_d, context.input.mRight, 0);
				KEY(SDLK_w, context.input.mUp,    0);
				KEY(SDLK_s, context.input.mDown,  0);

				default:
					break;
			}
			break;
		default:
			break;
	}
}

void pollEvents() {
	while( SDL_PollEvent( &context.event ) != 0 ) {
		switch (context.event.type) {
			case SDL_QUIT:
				context.shouldClose = 1;
				break;
			default:
				break;
		} handleInput();
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

void freeTextures() {
	for (u8 i = 0; i < TEXURES_LEN; ++i) {
		SDL_DestroyTexture(context.textures[i]);
	}
}

void cleanGfx() {
	freeTextures();
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
	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(SDL_SWSURFACE, w, h, 24, SDL_PIXELFORMAT_ARGB8888);
	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);
	for (u8 y = 0; y < h; ++y) {
		for (u8 x = 0; x < w; ++x) {
			int p = (y*w+x)*3;
			u32 colour;
			
			colour =
				(255 << 24) | (data[p] << 16) | ( data[p+1] << 8 ) | (data[p+2]);
			if (!(data[p] == 230 && data[p+1] == 24 && data[p+2] == 255)) {
				SDL_FillRect(surface,
					&(SDL_Rect) {x, y, 1, 1},
					colour);
			}
		}
	}
	context.textures[index] = SDL_CreateTextureFromSurface(context.renderer, surface);

	SDL_SetTextureBlendMode(context.textures[index], SDL_BLENDMODE_BLEND);
	SDL_FreeSurface(surface);
}

void drawTexture(i32 x, i32 y, u8 w, u8 h, u8 index, u8 sw, u8 sh, u8 hf, u8 vf) {
	SDL_RenderCopy(context.renderer, context.textures[index],
		&(SDL_Rect) {hf*sw, vf*sh, sw, sh},
		&(SDL_Rect) {x, y, w, h});
}

Input getInput() {
	return context.input;
}

