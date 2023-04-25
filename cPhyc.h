/*
 * File: cPhyc.h
 * Author: Nico Lindström
 * Copyright: (c) 2022 Nico Lindström 
 * 
 * NOTE: Depends on stdTuhkis (https://github.com/Tuhkis/stdTuhkis)
 *
 * This is a header only library for AABB based physics
 *
 *
 * Documentation:
 *   Types:
 *     Rect
 *       A rectangle structure that stores its position and dimensions as 32 bit ints.
 *
 *   Macros:
 *     collideRect(rect1, rect2)
 *       Checks whetever two Rect's overlap.
 *
 *   Methods:
 *     moveAndCollide(rect, tiles, tilesLen, velx, vely)
 *       Moves provided Rect pointer by velx and vely and will not go through tiles, provided tilesLen (The length of the tiles array) is provided.
 *
*/

#pragma once
#define CPHYC_H

typedef struct {
	int x, y, w, h;
} Rect;

#define collideRect(rect1, rect2) (rect1.x + rect1.w > rect2.x && rect1.x < rect2.x + rect2.w && rect1.y + rect1.h > rect2.y && rect1.y < rect2.y + rect2.h)

static void moveAndCollide(Rect* rect, Rect tiles[], int tilesLen, int velx, int vely) {
	Rect r = *rect;

	r.x += velx;
	for (int t = 0; t < tilesLen; t++) {
		if ( collideRect(r, tiles[t]) ) {
			if ( velx > 0 )
				r.x = tiles[t].x - r.w;
			else if (velx < 0)
				r.x = tiles[t].x + tiles[t].w;
		}
	}

	r.y += vely;
	for (int t = 0; t < tilesLen; t++) {
		if ( collideRect(r, tiles[t]) ) {
			if ( vely > 0 )
				r.y = tiles[t].y - r.h;
			else if (vely < 0)
				r.y = tiles[t].y + tiles[t].h;
		}
	}

	*rect = r;
}

