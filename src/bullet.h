#pragma once
#define BULLET_H

#include "util.h"

#define BULLET_SPEED 512
typedef struct {
	i32 x,  y;
	i32 vx, vy;
} Bullet;

Bullet* newBullet(i32 x, i32 y, u16 rot);
void tickBullet(Bullet* b, float dt);
void drawBullet(Bullet* b);

