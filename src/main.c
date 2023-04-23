#include <stdio.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"

#include "../res/grass-tile.h"

#define FPS 60

u8 main(int argc, char* argv[]) {
	openDisplay();
	while (shouldClose() != 1) {
		pollEvents();
		tick(FPS);
		clearScreen(55, 55, 55);
		for (u8 y = 0; y < 12; ++y) {
			for (u8 x = 0; x < 12; ++x) {
				int p = (y*12+x)*3;
				drawRect(x * 10, y * 10, 10, 10,
					GRASS_TILE[p], GRASS_TILE[p+1], GRASS_TILE[p+2]);
			}
		}
		display();
	}
	cleanGfx();
	return 0;
}

