#include "bullet.h"

#include <stdlib.h>
#include <math.h>

#include "gfx.h"

Bullet* newBullet(i32 x, i32 y, u16 rot) {
	Bullet* b = malloc(sizeof(Bullet));
	b->x = x;
	b->y = y;

	b->vx = cosf(rot)  * BULLET_SPEED;
	b->vy = -sinf(rot) * BULLET_SPEED;

	return b;
}

void tickBullet(Bullet* b, float dt) {
	b->x += b->vx * dt;
	b->y += b->vy * dt;
}

void drawBullet(Bullet* b) {
	drawTexture(
		b->x, b->y,
		16, 16, 1, 16, 16, 0, 0, 0
	);
}

