#include <stdio.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"

#include "../res/grass-tile.h"

#define FPS 60

u8 main(int argc, char* argv[]) {
	openDisplay();
	loadTextureToIndex(12, 12, GRASS_TILE, 0);
	while (shouldClose() != 1) {
		pollEvents();
		tick(FPS);
		clearScreen(55, 55, 55);
		drawTexture(0, 0, 64, 64, 0);
		
		display();
	}
	cleanGfx();
	return 0;
}

