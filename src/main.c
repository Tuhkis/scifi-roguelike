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
		{0, 0, 1, 0, 0}
	} };

	float x = 0;
	float y = 0;
	Player* p = newPlayer(64, 64);
	while (shouldClose() != 1) {
		pollEvents();
		float dt = tick(FPS);
		if (getInput().mLeft == 1)
			x -= dt * 256.f;
		if (getInput().mRight == 1)
			x += dt * 256.f;
		if (getInput().mUp == 1)
			y -= dt * 256.f;
		if (getInput().mDown == 1)
			y += dt * 256.f;

		clearScreen(55, 55, 55);
		renderTiles(t);

		drawTexture(x, y, 64, 64, 2, 16, 16, 0, 0);
		M_DRAW_ENTITY(p->base, 255, 255, 0);
		
		display();
	}
	cleanGfx();
	return 0;
}

