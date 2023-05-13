#include "tilemap.h"

#include "gfx.h"
#include "camera.h"

void renderTiles(Tilemap tiles, Camera cam) {
	for (u16 t = 0; t < TILES_LEN; ++t) {
		drawTexture(
			tiles.tiles[t].r.x - CAMX(cam), tiles.tiles[t].r.y - CAMY(cam),
			TILESIZE, TILESIZE,
			tiles.tiles[t].spr, 16, 16,
			tiles.tiles[t].fv, tiles.tiles[t].fh, 0);
	}
}

