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

void tickBullet(Bullet* b, float dt) {
	// i32 vx = b->vx;
	// i32 vy = floorf(b->vy * BULLET_SPEED * dt);
	float vx = (b->vx) / DISTANCE(0, 0, b->vx, b->vy);
	float vy = (b->vy) / DISTANCE(0, 0, b->vx, b->vy);

	b->x += (roundf(vx * BULLET_SPEED * dt));
	b->y += (roundf(vy * BULLET_SPEED * dt));
}

void drawBullet(Bullet* b, Camera cam) {
	drawTexture(
		b->x - CAMX(cam), b->y - CAMY(cam),
		16, 16, 1, 16, 16, 0, 0, 0
	);
}

