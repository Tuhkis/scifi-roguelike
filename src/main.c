#include <stdio.h>
#include <math.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"

#include "res.c"

#define FPS 30

u8 main(int argc, char* argv[]) {
	openDisplay();
	loadTextureToIndex(16, 16, SMILE_IMG, 0);
	loadTextureToIndex(12, 12, TILE_IMG,  1);
	loadTextureToIndex(12, 12, PLAYER_IMG,  2);

	float x = 0;
	while (shouldClose() != 1) {
		float dt = tick(FPS);
		x += dt * 2.f;
		pollEvents();
		// clearScreen(55, 55, 55);
		for (u8 y = 0; y < 10; ++y) {
			for (u8 x = 0; x < 16; ++x) {
				drawTexture(x*64, y*64, 64, 64, 1);
			}
		}
		drawTexture(75 + sinf(x*2.5f) * 64, 100 + cosf(x) * 75, 64, 64, 0);
		
		display();
	}
	cleanGfx();
	return 0;
}

