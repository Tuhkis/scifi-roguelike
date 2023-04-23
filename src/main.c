#include <stdio.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"

#include "../res/tile.h"
#include "../res/smile.h"

#define FPS 60

u8 main(int argc, char* argv[]) {
	openDisplay();
	loadTextureToIndex(16, 16, SMILE_IMG, 0);
	while (shouldClose() != 1) {
		float dt = tick(FPS);
		// printf("%s%f\n", "DT: ", dt);
		pollEvents();
		clearScreen(55, 55, 55);
		for (u8 y = 0; y < 10; ++y) {
			for (u8 x = 0; x < 16; ++x) {
				drawTexture(x*64, y*64, 64, 64, 0);
			}
		}
		
		display();
	}
	cleanGfx();
	return 0;
}

