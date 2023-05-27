#include "bullet.h"

#include <stdlib.h>
#include <math.h>

#include "gfx.h"
#include "util.h"

Bullet* newBullet(i32 x, i32 y, i16 dirX, i16 dirY) {
	Bullet* b = malloc(sizeof(Bullet));
	b->x = x;
	b->y = y;

	b->vx = dirX * BULLET_SPEED;
	b->vy = dirY * BULLET_SPEED;

	return b;
}

void tickBullet(Bullet* b, float dt, Tilemap tiles) {
	// i32 vx = b->vx;
	// i32 vy = floorf(b->vy * BULLET_SPEED * dt);
	float vx = (b->vx) / DISTANCE(0, 0, b->vx, b->vy);
	float vy = (b->vy) / DISTANCE(0, 0, b->vx, b->vy);

	b->x += (roundf(vx * BULLET_SPEED * dt));
	b->y += (roundf(vy * BULLET_SPEED * dt));

	u8 c = 0;
	Rect ti = { b->x, b->y, 16, 16 };
	for ( u16 t = 0; t < TILES_LEN; ++t ) {
		if ( collideRect(ti, tiles.tiles[t].r) ) {
			c = 1;
		}
	}
	if (c == 1) {
		b->x = 0;
		b->y = 0;
		b->vx = 0;
		b->vy = 0;

		b = NULL;
	}
}

void drawBullet(Bullet* b, Camera cam) {
	if (b->vx != 0 || b->vy != 0)
		drawTexture(
			b->x - cam.x, b->y - cam.y,
			16, 16, 3, 16, 16, 0, 0, 0
		);
}

