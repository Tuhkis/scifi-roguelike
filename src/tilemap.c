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

u8 indx = 0;
void addRoomToTiles(Tilemap* tiles, i32 x, i32 y) {
	for (u8 i = ROOM_H; i > 0; --i) {
		Tile t = TILE((0 + x * ROOM_W), (i + y * ROOM_H), 1, 0, 0);
		tiles->tiles[HASHTILE(t)] = t;
		++indx;
	}
	for (u8 i = ROOM_H; i > 0; --i) {
		Tile t = TILE((ROOM_W + 1 + x * ROOM_W), (i + y * ROOM_H), 1, 0, 0);
		tiles->tiles[HASHTILE(t)] = t;
		++indx;
	}

	for (u8 i = ROOM_W; i > 0; --i) {
		Tile t = TILE((i + x * ROOM_W), (y * ROOM_H), 1, 0, 0);
		tiles->tiles[HASHTILE(t)] = t;
		++indx;
	}
	for (u8 i = ROOM_W; i > 0; --i) {
		Tile t = TILE((i + x * ROOM_W), (ROOM_H + 1 + y * ROOM_H), 1, 0, 0);
		tiles->tiles[HASHTILE(t)] = t;
		++indx;
	}
	// for (u8 i = ROOM_H; i > 0; --i)
	// 	tiles->tiles[i] = TILE(ROOM_W, i, 1, 0, 0);
}

