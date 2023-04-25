#pragma once
#define TILEMAP_H

#include "../cPhyc/cPhyc.h"

#include "util.h"

typedef struct {
	Rect r;
	u8 spr, fv, fh;
} Tile;

#define TILES_LEN 512
#define TILESIZE  64

typedef struct {
	Tile tiles[TILES_LEN];
} Tilemap;

void renderTiles(Tilemap tiles);

