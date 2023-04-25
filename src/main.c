#include <stdio.h>
#include <math.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"
#include "input.h"

#include "res.c"

#define FPS 30

u8 main(int argc, char* argv[]) {
	openDisplay();
	loadTextureToIndex(16, 16, TILE2_IMG,  0);
	loadTextureToIndex(16, 16, TILE_IMG,   1);
	loadTextureToIndex(64, 64, PLAYER_IMG, 2);

	float x = 0;
	while (shouldClose() != 1) {
		pollEvents();
		float dt = tick(FPS);
		if (getInput().mLeft == 1)
			x += dt * 64.f;
		// clearScreen(55, 55, 55);
		for (u8 y = 0; y < 10; ++y) {
			for (u8 x = 0; x < 16; ++x) {
				drawTexture(x*64, y*64, 64, 64, 1, 16, 16, 0, 0);
			}
		}
		for (u8 x = 0; x < 14; ++x) {
			drawTexture(x*64+64, 0, 64, 64, 0, 16, 16, 0, 0);
		}
		drawTexture(x, 75, 64, 64, 2, 16, 16, 0, 0);
		
		display();
	}
	cleanGfx();
	return 0;
}

