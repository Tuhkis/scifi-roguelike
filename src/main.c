#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"
#include "gfx.h"
#include "fps.h"
#include "input.h"
#include "tilemap.h"
#include "player.h"
#include "entity.h"
#include "bullet.h"

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

	Bullet* p_bullets[64] = { 0 };
	for (u8 i = 0; i < 64; ++i)
		p_bullets[i] = NULL;

	while (shouldClose() != 1) {
		pollEvents();
		float dt = tick(FPS);
		if (dt < 0.1) {
			playerTick(p, dt, tiles, p_bullets);
			for (u8 i = 0; i < 64; ++i)
				tickBullet(p_bullets[i], dt);

			clearScreen(55, 55, 55);
			renderTiles(tiles);

			drawPlayer(p);
			for (u8 i = 0; i < 64; ++i)
				drawBullet(p_bullets[i]);
		
			display();
		}
	}
	cleanGfx();
	free(p);
	return 0;
}

