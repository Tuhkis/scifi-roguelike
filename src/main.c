#include <stdio.h>
#include <math.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"
#include "input.h"
#include "tilemap.h"
#include "player.h"
#include "entity.h"

#include "res.c"

#define FPS 60

u8 main(int argc, char* argv[]) {
	openDisplay();
	// loadTextureToIndex(16, 16, TILE2_IMG,  0);
	loadTextureToIndex(16, 16, TILE_IMG,   1);
	loadTextureToIndex(64, 64, PLAYER_IMG, 2);

	Tilemap tiles = { {
		{{0, 0, 64, 64},     1, 0, 0},
		{{64, 0, 64, 64},    1, 0, 0},
		{{128, 0, 64, 64},   1, 0, 0},
		{{128, 64, 64, 64},  1, 0, 0},
		{{128, 128, 64, 64}, 1, 0, 0},
		{{128, 256, 64, 64}, 1, 0, 0},
	} };

	Player* p = newPlayer(64, 64);
	while (shouldClose() != 1) {
		pollEvents();
		float dt = tick(FPS);

		playerTick(p, dt, tiles);

		clearScreen(55, 55, 55);
		renderTiles(tiles);
		static const ENTITY_ID i = ENT_PLAYER;

		drawPlayer(p);
		
		display();
	}
	cleanGfx();
	return 0;
}

