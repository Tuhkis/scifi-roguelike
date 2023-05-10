#pragma once
#define BULLET_H

#include "util.h"

#define BULLET_SPEED 128.f
typedef struct {
	i32 x,  y;
	float vx, vy;
} Bullet;

Bullet* newBullet(i32 x, i32 y, i16 dirX, i16 dirY);
void tickBullet(Bullet* b, float dt);
void drawBullet(Bullet* b);

