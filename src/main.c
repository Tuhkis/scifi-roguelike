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

	Tilemap t = { {
		{{0, 0, 64, 64}, 1, 0, 0}
	} };

	Player* p = newPlayer(64, 64);
	while (shouldClose() != 1) {
		pollEvents();
		float dt = tick(FPS);

		playerTick(p, dt);

		clearScreen(55, 55, 55);
		renderTiles(t);
		static const ENTITY_ID i = ENT_PLAYER;

		drawPlayer(p);
		// drawTexture(x, y, 64, 64, 2, 16, 16, 0, 0);
		// M_DRAW_ENTITY(p->base, 255, 255, 0);
		
		display();
	}
	cleanGfx();
	return 0;
}

