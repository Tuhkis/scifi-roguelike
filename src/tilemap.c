#include "tilemap.h"

#include "gfx.h"

void renderTiles(Tilemap tiles) {
	for (u16 t = 0; t < TILES_LEN; ++t) {
		drawTexture(
			tiles.tiles[t].r.x * TILESIZE, tiles.tiles[t].r.y * TILESIZE,
			TILESIZE, TILESIZE,
			tiles.tiles[t].spr, 16, 16,
			tiles.tiles[t].fv, tiles.tiles[t].fh, 0);
	}
}

