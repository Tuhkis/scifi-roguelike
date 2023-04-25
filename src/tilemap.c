#include "tilemap.h"

#include "gfx.h"

void renderTiles(Tilemap tiles) {
	for (u16 t = 0; t < TILES_LEN; ++t) {
		drawTexture(
			tiles.tiles[t].x * TILESIZE, tiles.tiles[t].y * TILESIZE,
			TILESIZE, TILESIZE,
			tiles.tiles[t].spr, 16, 16,
			tiles.tiles[t].fv, tiles.tiles[t].fh);
	}
}

