#pragma once
#define TILEMAP_H

#include "util.h"
#include "camera.h"

typedef struct {
	i32 x, y, w, h;
} Rect;

typedef struct {
	Rect r;
	u8 spr, fv, fh;
} Tile;

#define TILES_LEN 512
#define TILESIZE  64

typedef struct {
	Tile tiles[TILES_LEN];
} Tilemap;

#define collideRect(rect1, rect2) \
	(rect1.x + rect1.w > rect2.x && \
	 rect1.x < rect2.x + rect2.w && \
	 rect1.y + rect1.h > rect2.y && \
	 rect1.y < rect2.y + rect2.h)

static void moveAndCollide(Rect* rect, Tilemap tiles, int tilesLen, int velx, int vely) {
	Rect r = *rect;

	r.x += velx;
	for (int t = 0; t < tilesLen; t++) {
		if ( collideRect(r, tiles.tiles[t].r) ) {
			if ( velx > 0 )
				r.x = tiles.tiles[t].r.x - r.w;
			else if (velx < 0)
				r.x = tiles.tiles[t].r.x + tiles.tiles[t].r.w;
		}
	}

	r.y += vely;
	for (int t = 0; t < tilesLen; t++) {
		if ( collideRect(r, tiles.tiles[t].r) ) {
			if ( vely > 0 )
				r.y = tiles.tiles[t].r.y - r.h;
			else if (vely < 0)
				r.y = tiles.tiles[t].r.y + tiles.tiles[t].r.h;
		}
	}

	*rect = r;
}

void renderTiles(Tilemap tiles, Camera cam);

